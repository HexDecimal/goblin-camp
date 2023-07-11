cmake_minimum_required(VERSION 3.12...3.26)

set(USE_VCPKG FALSE CACHE BOOL "Use Vcpkg for package management")

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if (USE_VCPKG)
    set(CMAKE_TOOLCHAIN_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
  endif()
endif()

project(GoblinCamp C CXX)

add_executable("goblin-camp")

SET(GCAMP_VERSION "0.24")
SET(GCAMP_VERSION_IS_RELEASE NO)

target_compile_features("goblin-camp" PRIVATE cxx_std_17)

if (MSVC)
  target_compile_options("goblin-camp" PRIVATE /bigobj)  # Game.cpp might be too large
endif()

target_compile_definitions("goblin-camp" PRIVATE "-DBOOST_NO_CXX11_SCOPED_ENUMS -DBOOST_NO_SCOPED_ENUMS")
#  -DBOOST_NO_CXX11_SCOPED_ENUMS -DBOOST_NO_SCOPED_ENUMS  https://stackoverflow.com/questions/18783790/boostfilesystemcopy-file-missing-symbol-in-c11 
# and Goblin Camp/src/data/Data.cpp fs::copy_file(source, target);

# Add the path for the script to find libtcod
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

#### Build with Address Sanitizer. Uncomment it manually
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fsanitize=address -g -O0")
#SET(CMAKE_CXX_COMPILER "/usr/bin/clang++-11")

SET(USE_THREADS TRUE CACHE BOOL "Enable threads")

IF (USE_THREADS)
  MESSAGE(STATUS "Using threads")
ELSE()
  MESSAGE(STATUS "Using no threads")
ENDIF()

SET(GOBLIN_CAMP_BINDIR ${CMAKE_INSTALL_PREFIX}/games CACHE PATH "Path to Goblin Camp binary")
SET(GOBLIN_CAMP_DATA_BASE_DIR "${CMAKE_INSTALL_PREFIX}/share" CACHE PATH "Base Data Dir Path")
SET(GOBLIN_CAMP_SHAREDIR "${GOBLIN_CAMP_DATA_BASE_DIR}/games/goblin-camp" CACHE PATH "Path to Goblin Camp shared files")


find_package(Boost REQUIRED)
IF (USE_THREADS OR ( ${Boost_VERSION} LESS 106701) ) # for boost 1.67 we have to find threads anyway for some reason
  find_package(Boost REQUIRED COMPONENTS thread)
  IF (USE_THREADS)
    target_link_libraries("goblin-camp" PRIVATE Boost::thread)
  ENDIF()
ENDIF()

find_package(Boost REQUIRED COMPONENTS filesystem iostreams serialization system)

set(FORCE_PYTHON27 FALSE CACHE BOOL "Build using Python 2")
if (FORCE_PYTHON27)
  find_package(Python2 COMPONENTS Development REQUIRED)
  MESSAGE(STATUS "Using Python ${Python2_VERSION}")
  set(PYTHON_COMPONENT python${Python2_VERSION_MAJOR}${Python2_VERSION_MINOR})
else()
  find_package(Python3 COMPONENTS Development REQUIRED)
  MESSAGE(STATUS "Using Python ${Python3_VERSION}")
  set(PYTHON_COMPONENT python${Python3_VERSION_MAJOR}${Python3_VERSION_MINOR})
endif()

find_package(Boost COMPONENTS ${PYTHON_COMPONENT} REQUIRED)

if (POLICY CMP0072)
  set(OpenGL_GL_PREFERENCE GLVND)
endif()

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(libtcod CONFIG REQUIRED)

target_link_libraries("goblin-camp" PRIVATE
  #$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>  # TODO: Setup SDLmain
  $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
  $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
  Python3::Python
  Boost::boost
  Boost::filesystem
  Boost::iostreams
  Boost::${PYTHON_COMPONENT}
  Boost::serialization
  Boost::system
  OpenGL::GL
  libtcod::libtcod
)
# Explciitly include header-only Boost libraries for the configuration provider
target_include_directories("goblin-camp" PRIVATE ${Boost_INCLUDE_DIRS})

ADD_SUBDIRECTORY("game")

SET (data_SRC
"game/src/data/Config.cpp"
"game/src/data/Data.cpp"
"game/src/data/Mods.cpp"
"game/src/data/Paths.cpp"
"game/src/data/Serialization.cpp"
"game/src/data/Tilesets.cpp"
)
SET (main_SRC
"game/src/Announce.cpp"
"game/src/Attack.cpp"
"game/src/Blood.cpp"
"game/src/Camp.cpp"
"game/src/Construction.cpp"
"game/src/Container.cpp"
"game/src/Coordinate.cpp"
"game/src/Door.cpp"
"game/src/Entity.cpp"
"game/src/Events.cpp"
"game/src/Faction.cpp"
"game/src/Farmplot.cpp"
"game/src/Filth.cpp"
"game/src/Fire.cpp"
"game/src/GCamp.cpp"
"game/src/Game.cpp"
"game/src/Item.cpp"
"game/src/Job.cpp"
"game/src/JobManager.cpp"
"game/src/KuhnMunkres.cpp"
"game/src/Logger.cpp"
"game/src/Map.cpp"
"game/src/MapMarker.cpp"
"game/src/MapRenderer.cpp"
"game/src/NPC.cpp"
"game/src/NatureObject.cpp"
"game/src/Random.cpp"
"game/src/SpawningPool.cpp"
"game/src/Spell.cpp"
"game/src/Squad.cpp"
"game/src/Stats.cpp"
"game/src/StatusEffect.cpp"
"game/src/StockManager.cpp"
"game/src/Stockpile.cpp"
"game/src/TCODMapRenderer.cpp"
"game/src/Tile.cpp"
"game/src/Trap.cpp"
"game/src/UI.cpp"
"game/src/Water.cpp"
"game/src/Weather.cpp"
"game/src/Version.cpp"
)

SET (scripting_SRC
"game/src/scripting/API.cpp"
"game/src/scripting/Engine.cpp"
"game/src/scripting/Event.cpp"
"game/src/scripting/_gcampapi/Functions.cpp"
"game/src/scripting/_gcampapi/LoggerStream.cpp"
"game/src/scripting/_gcampapi/PyConstruction.cpp"
"game/src/scripting/_gcampapi/PyItem.cpp"
)

SET (UI_SRC
"game/src/UI/AnnounceDialog.cpp"
"game/src/UI/ConstructionDialog.cpp"
"game/src/UI/DevConsole.cpp"
"game/src/UI/JobDialog.cpp"
"game/src/UI/Menu.cpp"
"game/src/UI/MessageBox.cpp"
"game/src/UI/NPCDialog.cpp"
"game/src/UI/SideBar.cpp"
"game/src/UI/SquadsDialog.cpp"
"game/src/UI/StockManagerDialog.cpp"
"game/src/UI/Tooltip.cpp"
"game/src/UI/UIComponents.cpp"
)

SET (tileRenderer_SRC
"game/src/tileRenderer/ConstructionSprite.cpp"
"game/src/tileRenderer/DrawConstructionVisitor.cpp"
"game/src/tileRenderer/ItemSprite.cpp"
"game/src/tileRenderer/NatureObjectSpriteSet.cpp"
"game/src/tileRenderer/NPCSprite.cpp"
"game/src/tileRenderer/PermutationTable.cpp"
"game/src/tileRenderer/SpellSpriteSet.cpp"
"game/src/tileRenderer/Sprite.cpp"
"game/src/tileRenderer/SpriteSetFactories.cpp"
"game/src/tileRenderer/StatusEffectSprite.cpp"
"game/src/tileRenderer/TerrainSprite.cpp"
"game/src/tileRenderer/TileSet.cpp"
"game/src/tileRenderer/TileSetLoader.cpp"
"game/src/tileRenderer/TilesetParserV1.cpp"
"game/src/tileRenderer/TilesetParserV2.cpp"
"game/src/tileRenderer/TileSetRenderer.cpp"
"game/src/tileRenderer/TileSetTexture.cpp"

"game/src/tileRenderer/sdl/SDLSprite.cpp"
"game/src/tileRenderer/sdl/SDLTilesetRenderer.cpp"

"game/src/tileRenderer/ogl/OGLFunctionExt.cpp"
"game/src/tileRenderer/ogl/OGLResources.cpp"
"game/src/tileRenderer/ogl/OGLSprite.cpp"
"game/src/tileRenderer/ogl/OGLTilesetRenderer.cpp"
"game/src/tileRenderer/ogl/OGLViewportLayer.cpp"

)

IF (UNIX)
  target_sources("goblin-camp" PRIVATE
    "game/src/platform/unix/main.cpp"
    "game/src/platform/linux/DataImpl.cpp"
  )
ELSEIF(WIN32)
  target_sources("goblin-camp" PRIVATE
    "game/src/platform/windows/CommandLine.cpp"
    "game/src/platform/windows/CrashHandler.cpp"
    "game/src/platform/windows/DataImpl.cpp"
    "game/src/platform/windows/DebugImpl.cpp"
    "game/src/platform/windows/main.cpp"
    "game/src/platform/windows/TSSCleanup.cpp"
  )
  target_include_directories("goblin-camp" PRIVATE "game")  # To include "goblin-camp.rch"
  set_target_properties("goblin-camp" PROPERTIES WIN32_EXECUTABLE TRUE)  # Use WinMain
  target_link_libraries("goblin-camp" PRIVATE DBGHELP)  # Link MiniDumpWriteDump function
ENDIF()

target_sources("goblin-camp" PRIVATE ${main_SRC} ${data_SRC} ${scripting_SRC} ${libtcod_SRC} ${UI_SRC} ${tileRenderer_SRC})
target_include_directories("goblin-camp" PRIVATE BEFORE "game/include")
target_include_directories("goblin-camp" PRIVATE "vendor/python-modules")

# Add headers as sources for the configuration provider
file(GLOB_RECURSE game_headers CONFIGURE_DEPENDS "game/include/*.hpp")
target_sources("goblin-camp" PRIVATE ${game_headers})

target_compile_definitions("goblin-camp" PRIVATE GCAMP_USE_THREADS=$<BOOL:${USE_THREADS}>)
target_compile_definitions("goblin-camp" PRIVATE GCAMP_VERSION=\"${GCAMP_VERSION}\")
target_compile_definitions("goblin-camp" PRIVATE GCAMP_VERSION_IS_RELEASE=$<BOOL:${GCAMP_VERSION_IS_RELEASE}>)

# Workaround for missing pythonXX.lib
# https://github.com/microsoft/vcpkg/issues/5097#issuecomment-719635582
if(VCPKG_TOOLCHAIN)
  target_link_directories("goblin-camp" PRIVATE ${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/lib;${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/debug/lib)
endif()

INSTALL(TARGETS "goblin-camp" RUNTIME DESTINATION ${GOBLIN_CAMP_BINDIR})
