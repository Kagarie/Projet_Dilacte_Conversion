cmake_minimum_required(VERSION 3.0)
project(Convertisseur VERSION 0.0.1 DESCRIPTION "NumberToLetter library, C project")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

enable_testing()


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
add_subdirectory(src)
add_subdirectory(docs)

#add_subdirectory(test)

set(CPACK_GENERATOR "ZIP")
set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_IGNORE_FILES ".*/\\\\..*;~$;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)
