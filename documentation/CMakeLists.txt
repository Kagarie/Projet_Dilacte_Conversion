cmake_minimum_required(VERSION 2.8)

project(Convertisseur)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
add_subdirectory(docs)
add_subdirectory(src)

set(CPACK_GENERATOR "ZIP")
set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_IGNORE_FILES ".*/\\\\..*;~$;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)
