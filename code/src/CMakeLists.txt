cmake_minimum_required(VERSION 3.0)
project(Convertisseur VERSION 0.0.1 DESCRIPTION "ChiffreEnLettre ma library projet de C")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

include_directories(/usr/local/lib/dilacte)
link_directories(/usr/local/lib/dilacte)


add_subdirectory(chiffreEnLettre)
#add_subdirectory(array)
add_subdirectory(utils)



#add_executable(main main.c main.h)

#include_directories(/lib/)
#link_directories(/lib/libyaml.so /usr/local/lib/dilacte)
#target_link_libraries(main libyaml.so)

#target_link_libraries(main libutils.so)
