
# TODO compile python modules into bitecode before (.pyc) before installing

IF (${Boost_PYTHON3_FOUND})
  INSTALL(FILES __gcdevconsole__.py DESTINATION ${GOBLIN_CAMP_SHAREDIR}/lib)
ELSE()
  INSTALL(FILES __gcdevconsole__.py_2.7 DESTINATION ${GOBLIN_CAMP_SHAREDIR}/lib RENAME __gcdevconsole__.py)
ENDIF()
INSTALL(DIRECTORY gcamp gcamp_core tilesets_core DESTINATION ${GOBLIN_CAMP_SHAREDIR}/lib)


