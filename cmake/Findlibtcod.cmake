
find_library(libtcod_LIBRARY NAMES tcod tcod)
find_library(libtcodxx_LIBRARY NAMES tcodxx tcod)

SET(libtcod_LIBRARIES ${libtcod_LIBRARY} ${libtcodxx_LIBRARY})

find_path(libtcod_INCLUDE_DIR libtcod/libtcod.hpp)

find_package(PackageHandleStandardArgs QUIET)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(libtcod REQUIRED_VARS libtcod_LIBRARIES libtcod_INCLUDE_DIR)

SET(tcod_LIBRARY ${libtcod_LIBRARY})  #backward compatibility
