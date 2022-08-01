cmake_minimum_required(VERSION 2.8.9) # Do not raise it without a reason. Bump only when you use some feature that is not supported by older verions

# set the project name
project(GoblinCamp C CXX)

SET(GCAMP_VERSION "0.221")
SET(GCAMP_VERSION_IS_RELEASE YES)

SET(CMAKE_CXX_FLAGS "-std=c++17 -DBOOST_NO_CXX11_SCOPED_ENUMS -DBOOST_NO_SCOPED_ENUMS")  # FIXME move to add_compile_options() later
#  -DBOOST_NO_CXX11_SCOPED_ENUMS -DBOOST_NO_SCOPED_ENUMS  https://stackoverflow.com/questions/18783790/boostfilesystemcopy-file-missing-symbol-in-c11 
# and Goblin Camp/src/data/Data.cpp fs::copy_file(source, target);

# Add the path for the script to find libtcod
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

#### Build wiht Address Sanitizer. Uncomment it manually
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fsanitize=address -g -O0")
#SET(CMAKE_CXX_COMPILER "/usr/bin/clang++-11")

IF (FORCE_PYTHON27)
  MESSAGE("-- Trying to force python2.7 build")
ENDIF()
SET(FORCE_PYTHON27 ${FORCE_PYTHON27} CACHE BOOL "" FORCE)

IF (NOT DEFINED USE_THREADS)
  SET(USE_THREADS 1) # Default value
ENDIF()
SET(USE_THREADS ${USE_THREADS} CACHE BOOL "" FORCE)

IF (USE_THREADS)
  MESSAGE("-- Using threads")
ELSE()
  MESSAGE("-- Using no threads")
ENDIF()

SET(GOBLIN_CAMP_BINDIR ${CMAKE_INSTALL_PREFIX}/games CACHE PATH "Path to Goblin Camp binary")
SET(GOBLIN_CAMP_DATA_BASE_DIR "${CMAKE_INSTALL_PREFIX}/share" CACHE PATH "Base Data Dir Path")
SET(GOBLIN_CAMP_SHAREDIR "${GOBLIN_CAMP_DATA_BASE_DIR}/games/goblin-camp" CACHE PATH "Path to Goblin Camp shared files")


find_package(Boost REQUIRED)
IF (USE_THREADS OR ( ${Boost_VERSION} LESS 106701) ) # for boost 1.67 we have to find threads anyway for some reason
  find_package(Boost REQUIRED COMPONENTS thread)
ENDIF()

find_package(Boost REQUIRED COMPONENTS system filesystem serialization iostreams)
find_package(Boost COMPONENTS python REQUIRED)

IF (FORCE_PYTHON27)
  SET(USE_PYTHON27 YES)
  SET(USE_PYTHON3 NO)
ELSE()
  find_package(Boost COMPONENTS python3)
  IF(${Boost_PYTHON3_FOUND})
    SET(USE_PYTHON27 NO)
    SET(USE_PYTHON3 YES)
  ELSE()
    SET(USE_PYTHON27 YES)
    SET(USE_PYTHON3 NO)
  ENDIF()
ENDIF()

IF(USE_PYTHON3)
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

SET (platform_SRC
"game/src/platform/linux/DataImpl.cpp"
)

add_executable("goblin-camp" "game/src/platform/unix/main.cpp" "game/src/GCamp.cpp" ${main_SRC} ${data_SRC} ${scripting_SRC} ${libtcod_SRC} ${UI_SRC} ${tileRenderer_SRC} ${platform_SRC})
include_directories("goblin-camp" "game/include")
include_directories("goblin-camp" "vendor/python-modules")

IF (USE_THREADS)
  target_compile_definitions("goblin-camp" PRIVATE GCAMP_USE_THREADS=1)
ELSE()
  target_compile_definitions("goblin-camp" PRIVATE GCAMP_USE_THREADS=0)
ENDIF()
target_compile_definitions("goblin-camp" PRIVATE GCAMP_VERSION=\"${GCAMP_VERSION}\")
IF (GCAMP_VERSION_IS_RELEASE)
  target_compile_definitions("goblin-camp" PRIVATE GCAMP_VERSION_IS_RELEASE=1)
ENDIF()

IF (${Boost_PYTHON3_FOUND})
  # touch will force install of static python lib
  # this will solve porblem with installing python3 version over python2.7 and vice versa
  add_custom_command (TARGET "goblin-camp"
                      POST_BUILD
                      COMMAND touch -h "${PROJECT_SOURCE_DIR}/game/lib/__gcdevconsole__.py"
                      )
ELSE()
  # touch will force install of static python lib
  # this will solve porblem with installing python3 version over python2.7 and vice versa
  add_custom_command (TARGET "goblin-camp"
                      POST_BUILD
                      COMMAND touch -h "${PROJECT_SOURCE_DIR}/game/lib/__gcdevconsole__.py_2.7"
                      )
ENDIF()


target_link_libraries("goblin-camp"
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  ${PYTHON_LIBRARIES}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SERIALIZATION_LIBRARY}
  ${Boost_IOSTREAMS_LIBRARY}
  ${ZLIB_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${libtcod_LIBRARIES}
)

IF (USE_THREADS)
  target_link_libraries("goblin-camp"
    ${Boost_THREAD_LIBRARY}
  )
ENDIF()

IF(USE_PYTHON3)
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
