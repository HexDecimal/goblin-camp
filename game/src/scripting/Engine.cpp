/* Copyright 2010-2011 Ilkka Halila
             2020-2022 Nikolay Shaplov (aka dhyan.nataraj)
This file is part of Goblin Camp.

Goblin Camp is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Goblin Camp is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License 
along with Goblin Camp. If not, see <http://www.gnu.org/licenses/>.*/
#include "stdafx.hpp"

#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <list>

#define BOOST_FILESYSTEM_VERSION 3
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>
#include <boost/python/detail/wrap_python.hpp>
#include <boost/python.hpp>

namespace py = boost::python;
namespace fs = boost::filesystem;

#include "data/Paths.hpp"
#include "scripting/Engine.hpp"
#include "scripting/API.hpp"
#include "scripting/_gcampapi/LoggerStream.hpp"
#include "Logger.hpp"

namespace Globals {
	py::object loadPackageFunc, printExcFunc;
	Script::API::LoggerStream stream;
}

namespace {
	void LogBootstrapException() {
		py::object excType, excValue, excTB;
		Script::ExtractException(excType, excValue, excTB);
		
		try {
			py::str strExcType  = py::str(excType);
			py::str strExcValue = py::str(excValue);
			
			LOG_FUNC("Python bootstrap error: [" << py::extract<char*>(strExcType) << "] " << py::extract<char*>(strExcValue), "LogBootstrapException");
		} catch (const py::error_already_set&) {
			LOG_FUNC("< INTERNAL ERROR >", "LogBootstrapException");
			PyErr_Print();
		}
	}
}

#if PY_MAJOR_VERSION >= 3
PyMODINIT_FUNC PyInit_zlib();
//PyMODINIT_FUNC PyInit_cStringIO();
PyMODINIT_FUNC PyInit__functools();
PyMODINIT_FUNC PyInit__weakref();
PyMODINIT_FUNC PyInit_time();
#else
PyMODINIT_FUNC initzlib();
PyMODINIT_FUNC initcStringIO();
PyMODINIT_FUNC init_functools();
PyMODINIT_FUNC init_weakref();
PyMODINIT_FUNC inittime();
#endif

namespace Script {
	const short version = 0;
	
	void Init(std::vector<std::string>& args) {
		LOG("Initialising the engine.");
		
		Py_NoSiteFlag = 1;
#if PY_MAJOR_VERSION >= 3
		PyImport_AppendInittab((char*) "_weakref",  PyInit__weakref);
		PyImport_AppendInittab((char*) "time",      PyInit_time);
		PyImport_AppendInittab((char*) "_funtools", PyInit__functools);
//		PyImport_AppendInittab((char*) "cStringIO", PyInit_cStringIO);
		PyImport_AppendInittab((char*) "zlib",      PyInit_zlib);
#else
		PyImport_AppendInittab((char*) "_weakref",  init_weakref);
		PyImport_AppendInittab((char*) "time",      inittime);
		PyImport_AppendInittab((char*) "_funtools", init_functools);
		PyImport_AppendInittab((char*) "cStringIO", initcStringIO);
		PyImport_AppendInittab((char*) "zlib",      initzlib);
#endif
		ExposeAPI();

		Py_InitializeEx(0);
#if PY_MAJOR_VERSION >= 3
		wchar_t * w_name;
		size_t w_name_len;
		w_name_len = mbstowcs(NULL, args[0].c_str(), 0);
		w_name = (wchar_t *)malloc((w_name_len + 1) * sizeof(wchar_t));
		if (! w_name) throw("Out of memory"); //FIXME do proper out of memory case
		mbstowcs(w_name, args[0].c_str(), w_name_len + 1);
		Py_SetProgramName(w_name);
		free(w_name);
#else
		Py_SetProgramName(const_cast<char*>(args[0].c_str()));
#endif
		LOG("Python " << Py_GetVersion());
		
		// Don't use default search path.
		{
		#ifdef WINDOWS
			char pathsep = ';';
		#else
			char pathsep = ':';
		#endif
			fs::path libDir = (Paths::Get(Paths::GlobalData) / "lib");
			
			std::string path = libDir.string();
			path += pathsep;

#if PY_MAJOR_VERSION >= 3
			std::mbstate_t state = std::mbstate_t();
			wchar_t * w_py_path = Py_GetPath();
			char *py_path;
			size_t py_path_len;
			py_path_len = wcsrtombs(NULL, (const wchar_t**) &w_py_path, 0, &state);
			py_path = (char *)malloc((py_path_len + 1) * sizeof(char));
			wcsrtombs(py_path, (const wchar_t**) &w_py_path, py_path_len + 1, &state);
			path += py_path; // When need common Python modules, use ones installed in the system
			free(py_path);
#else
			path += Py_GetPath(); // When need common Python modules, use ones installed in the system
#endif
			
			LOG("Python Library Path = " << path);
#if PY_MAJOR_VERSION >= 3
			wchar_t * w_path;
			size_t w_path_len;
			w_path_len = mbstowcs(NULL, path.c_str(), 0);
			w_path = (wchar_t *)malloc((w_path_len + 1) * sizeof(wchar_t));
			if (! w_path) throw("Out of memory"); //FIXME do proper out of memory case
			mbstowcs(w_path, path.c_str(), w_path_len + 1);
			PySys_SetPath(w_path);
			free(w_path);
#else
			PySys_SetPath(const_cast<char*>(path.c_str()));
#endif
		}
		
		try {
			// Get utility functions.
			LOG("Importing Python modules");
			py::object modImp = py::import("imp");
			py::object modTB  = py::import("traceback");
			
			Globals::printExcFunc    = modTB.attr("print_exception");
			Globals::loadPackageFunc = modImp.attr("load_package");
			
			LOG("Creating internal namespaces.");
			PyImport_AddModule("__gcmods__");
			PyImport_AddModule("__gcuserconfig__");
			PyImport_AddModule("__gcautoexec__");
			PyImport_AddModule("__gcdevconsole__");
			
			LOG("Setting up console namespace. If you get 'No module named XXXX' error message below, " <<
				"check " << Paths::Get(Paths::GlobalData) / "lib" << " and make sure that module is really there");
			fs::path file_name = Paths::Get(Paths::GlobalData) / "lib" / "__gcdevconsole__.py";
			if (fs::exists(file_name))
			{
				modImp.attr("load_source")("__gcdevconsole__", file_name.string());
			} else
			{
				LOG("ERROR. File not found: " << file_name );
				exit(20);
			}
			
			py::exec(
				"log.info('Console ready.')", py::import("__gcdevconsole__").attr("__dict__")
			);
		} catch (const py::error_already_set&) {
			LogBootstrapException();
			
			LOG("Bootstrap has failed, exiting.");
			exit(20);
		}
	}
	
	void Shutdown() {
		LOG("Shutting down engine.");
		
		ReleaseListeners();

		// Unset all global boost::python::objects to prevent crash after
		// finalize
		Globals::printExcFunc    = boost::python::object();
		Globals::loadPackageFunc = boost::python::object();

		Py_Finalize();
	}
	
	void LoadScript(const std::string& mod, const std::string& directory) {
		LOG("Loading '" << directory << "' into '__gcmods__." << mod << "'.");
		
		try {
			Globals::loadPackageFunc("__gcmods__." + mod, directory);
		} catch (const py::error_already_set&) {
			LogException();
		}
	}
	
	void ExtractException(py::object& excType, py::object& excValue, py::object& excTB) {
		PyObject *rawExcType, *rawExcValue, *rawExcTB;
		PyErr_Fetch(&rawExcType, &rawExcValue, &rawExcTB);
		
		excType  = py::object(py::handle<>(rawExcType));
		
		// "The value and traceback object may be NULL even when the type object is not."
		// http://docs.python.org/c-api/exceptions.html#PyErr_Fetch
		
		// So, set them to None initially.
		excValue = py::object();
		excTB    = py::object();
		
		// And convert to py::objects when they're not NULL.
		if (rawExcValue) {
			excValue = py::object(py::handle<>(rawExcValue));
		}
		
		if (rawExcTB) {
			excTB    = py::object(py::handle<>(rawExcTB));
		}
	}
	
	void LogException(bool clear) {
		if (PyErr_Occurred() == NULL) return;
		
		py::object none, excType, excVal, excTB;
		ExtractException(excType, excVal, excTB);
		PyErr_Clear();
		
		Logger::log << "**** Python exception occurred ****\n";
		try {
			Globals::printExcFunc(excType, excVal, excTB, none, boost::ref(Globals::stream));
		} catch (const py::error_already_set&) {
			Logger::log << " < INTERNAL ERROR > \n";
			PyErr_Print();
		}
		Logger::log << Logger::Suffix();
		
		if (!clear) {
			PyErr_Restore(excType.ptr(), excVal.ptr(), excTB.ptr());
		}
	}
}
