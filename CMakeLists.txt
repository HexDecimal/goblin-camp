cmake_minimum_required(VERSION 2.8.9) # Do not raise it without a reason. Bump only when you use some feature that is not supported by older verions

# set the project name
project(GoblinCamp C CXX)

SET(CMAKE_CXX_FLAGS "-std=c++17 -DBOOST_NO_CXX11_SCOPED_ENUMS -DBOOST_NO_SCOPED_ENUMS")  # FIXME move to add_compile_options() later
#  -DBOOST_NO_CXX11_SCOPED_ENUMS -DBOOST_NO_SCOPED_ENUMS  https://stackoverflow.com/questions/18783790/boostfilesystemcopy-file-missing-symbol-in-c11 
# and Goblin Camp/src/data/Data.cpp fs::copy_file(source, target);

# Add the path for the script to find libtcod
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

#### Build wiht Address Sanitizer. Uncomment it manually
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fsanitize=address -g -O0")
#SET(CMAKE_CXX_COMPILER "/usr/bin/clang++-11")


SET(GOBLIN_CAMP_BINDIR ${CMAKE_INSTALL_PREFIX}/games CACHE PATH "Path to Goblin Camp binary")
SET(GOBLIN_CAMP_DATA_BASE_DIR "${CMAKE_INSTALL_PREFIX}/share" CACHE PATH "Base Data Dir Path")
SET(GOBLIN_CAMP_SHAREDIR "${GOBLIN_CAMP_DATA_BASE_DIR}/games/goblin-camp" CACHE PATH "Path to Goblin Camp shared files")

find_package(Boost REQUIRED COMPONENTS thread system filesystem serialization iostreams)

find_package(Boost COMPONENTS python REQUIRED)
find_package(Boost COMPONENTS python3)

IF(${Boost_PYTHON3_FOUND})
  find_package(PythonLibs 3)
ELSE()
  if(${Boost_VERSION} GREATER 106699) # boost >= 1.67
      find_package(Boost COMPONENTS python27 REQUIRED)
      set(Boost_PYTHON_LIBRARY ${Boost_PYTHON27_LIBRARY})
  else()
      # boost python suffixes are determined by distributives
      # try different alternatives
      find_package(Boost OPTIONAL_COMPONENTS python27)
      if(Boost_PYTHON27_FOUND)
          set(Boost_PYTHON_LIBRARY ${Boost_PYTHON27_LIBRARY})
      else()
          find_package(Boost OPTIONAL_COMPONENTS python-py27)
          if(Boost_PYTHON-PY27_FOUND)
              set(Boost_PYTHON_LIBRARY ${Boost_PYTHON-PY27_LIBRARY})
          else()
              find_package(Boost COMPONENTS python REQUIRED)
          endif()
      endif()
  endif()
  find_package(PythonLibs 2.7)
ENDIF()


if (POLICY CMP0072)
  set(OpenGL_GL_PREFERENCE GLVND)
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(ZLIB)
find_package(OpenGL REQUIRED)
find_package(PNG REQUIRED)
find_package(libtcod REQUIRED)


include_directories(${SDL2_INCLUDE_DIR})
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${PNG_INCLUDE_DIR})
include_directories(${libtcod_INCLUDE_DIR})
include_directories(${libtcod_INCLUDE_DIR}/libtcod)


ADD_SUBDIRECTORY("Goblin Camp")

SET (data_SRC
"Goblin Camp/src/data/Config.cpp"
"Goblin Camp/src/data/Data.cpp"
"Goblin Camp/src/data/Mods.cpp"
"Goblin Camp/src/data/Paths.cpp"
"Goblin Camp/src/data/Serialization.cpp"
"Goblin Camp/src/data/Tilesets.cpp"
)
SET (main_SRC
"Goblin Camp/src/Announce.cpp"
"Goblin Camp/src/Attack.cpp"
"Goblin Camp/src/Blood.cpp"
"Goblin Camp/src/Camp.cpp"
"Goblin Camp/src/Construction.cpp"
"Goblin Camp/src/Container.cpp"
"Goblin Camp/src/Coordinate.cpp"
"Goblin Camp/src/Door.cpp"
"Goblin Camp/src/Entity.cpp"
"Goblin Camp/src/Events.cpp"
"Goblin Camp/src/Faction.cpp"
"Goblin Camp/src/Farmplot.cpp"
"Goblin Camp/src/Filth.cpp"
"Goblin Camp/src/Fire.cpp"
"Goblin Camp/src/GCamp.cpp"
"Goblin Camp/src/Game.cpp"
"Goblin Camp/src/Item.cpp"
"Goblin Camp/src/Job.cpp"
"Goblin Camp/src/JobManager.cpp"
"Goblin Camp/src/KuhnMunkres.cpp"
"Goblin Camp/src/Logger.cpp"
"Goblin Camp/src/Map.cpp"
"Goblin Camp/src/MapMarker.cpp"
"Goblin Camp/src/MapRenderer.cpp"
"Goblin Camp/src/NPC.cpp"
"Goblin Camp/src/NatureObject.cpp"
"Goblin Camp/src/Random.cpp"
"Goblin Camp/src/SpawningPool.cpp"
"Goblin Camp/src/Spell.cpp"
"Goblin Camp/src/Squad.cpp"
"Goblin Camp/src/Stats.cpp"
"Goblin Camp/src/StatusEffect.cpp"
"Goblin Camp/src/StockManager.cpp"
"Goblin Camp/src/Stockpile.cpp"
"Goblin Camp/src/TCODMapRenderer.cpp"
"Goblin Camp/src/Tile.cpp"
"Goblin Camp/src/Trap.cpp"
"Goblin Camp/src/UI.cpp"
"Goblin Camp/src/Water.cpp"
"Goblin Camp/src/Weather.cpp"
"Goblin Camp/src/Version.cpp"
)

SET (scripting_SRC
"Goblin Camp/src/scripting/API.cpp"
"Goblin Camp/src/scripting/Engine.cpp"
"Goblin Camp/src/scripting/Event.cpp"
"Goblin Camp/src/scripting/_gcampapi/Functions.cpp"
"Goblin Camp/src/scripting/_gcampapi/LoggerStream.cpp"
"Goblin Camp/src/scripting/_gcampapi/PyConstruction.cpp"
"Goblin Camp/src/scripting/_gcampapi/PyItem.cpp"
)

SET (UI_SRC
"Goblin Camp/src/UI/AnnounceDialog.cpp"
"Goblin Camp/src/UI/ConstructionDialog.cpp"
"Goblin Camp/src/UI/DevConsole.cpp"
"Goblin Camp/src/UI/JobDialog.cpp"
"Goblin Camp/src/UI/Menu.cpp"
"Goblin Camp/src/UI/MessageBox.cpp"
"Goblin Camp/src/UI/NPCDialog.cpp"
"Goblin Camp/src/UI/SideBar.cpp"
"Goblin Camp/src/UI/SquadsDialog.cpp"
"Goblin Camp/src/UI/StockManagerDialog.cpp"
"Goblin Camp/src/UI/Tooltip.cpp"
"Goblin Camp/src/UI/UIComponents.cpp"
)

SET (tileRenderer_SRC
"Goblin Camp/src/tileRenderer/ConstructionSprite.cpp"
"Goblin Camp/src/tileRenderer/DrawConstructionVisitor.cpp"
"Goblin Camp/src/tileRenderer/ItemSprite.cpp"
"Goblin Camp/src/tileRenderer/NatureObjectSpriteSet.cpp"
"Goblin Camp/src/tileRenderer/NPCSprite.cpp"
"Goblin Camp/src/tileRenderer/PermutationTable.cpp"
"Goblin Camp/src/tileRenderer/SpellSpriteSet.cpp"
"Goblin Camp/src/tileRenderer/Sprite.cpp"
"Goblin Camp/src/tileRenderer/SpriteSetFactories.cpp"
"Goblin Camp/src/tileRenderer/StatusEffectSprite.cpp"
"Goblin Camp/src/tileRenderer/TerrainSprite.cpp"
"Goblin Camp/src/tileRenderer/TileSet.cpp"
"Goblin Camp/src/tileRenderer/TileSetLoader.cpp"
"Goblin Camp/src/tileRenderer/TilesetParserV1.cpp"
"Goblin Camp/src/tileRenderer/TilesetParserV2.cpp"
"Goblin Camp/src/tileRenderer/TileSetRenderer.cpp"
"Goblin Camp/src/tileRenderer/TileSetTexture.cpp"

"Goblin Camp/src/tileRenderer/sdl/SDLSprite.cpp"
"Goblin Camp/src/tileRenderer/sdl/SDLTilesetRenderer.cpp"

"Goblin Camp/src/tileRenderer/ogl/OGLFunctionExt.cpp"
"Goblin Camp/src/tileRenderer/ogl/OGLResources.cpp"
"Goblin Camp/src/tileRenderer/ogl/OGLSprite.cpp"
"Goblin Camp/src/tileRenderer/ogl/OGLTilesetRenderer.cpp"
"Goblin Camp/src/tileRenderer/ogl/OGLViewportLayer.cpp"

)

SET (platform_SRC
"Goblin Camp/src/platform/linux/DataImpl.cpp"
)

add_executable("goblin-camp" "Goblin Camp/src/platform/unix/main.cpp" "Goblin Camp/src/GCamp.cpp" ${main_SRC} ${data_SRC} ${scripting_SRC} ${libtcod_SRC} ${UI_SRC} ${tileRenderer_SRC} ${platform_SRC})
include_directories("goblin-camp" "Goblin Camp/include")
include_directories("goblin-camp" "vendor/python-modules")

target_link_libraries("goblin-camp"
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  ${PYTHON_LIBRARIES}
  ${Boost_THREAD_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SERIALIZATION_LIBRARY}
  ${Boost_IOSTREAMS_LIBRARY}
  ${ZLIB_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${PNG_LIBRARY}
  ${libtcod_LIBRARIES}
)

IF(${Boost_PYTHON3_FOUND})
  target_link_libraries("goblin-camp"
    ${Boost_PYTHON3_LIBRARY}
  )
ELSE()
  IF(${Boost_PYTHON27_FOUND})
    target_link_libraries("goblin-camp"
      ${Boost_PYTHON27_LIBRARY}
    )
  ELSE()
    # older versions of boost does not know Boost_PYTHON[NN]_FOUND and Boost_PYTHON[NN]_LIBRARY so just link to ${Boost_PYTHON_LIBRARY} it is the only one
    # This branch can be removed later
    IF(${Boost_PYTHON_FOUND})
      target_link_libraries("goblin-camp"
        ${Boost_PYTHON_LIBRARY}
      )
    ENDIF()
  ENDIF()
ENDIF()

INSTALL(TARGETS "goblin-camp" RUNTIME DESTINATION ${GOBLIN_CAMP_BINDIR})
