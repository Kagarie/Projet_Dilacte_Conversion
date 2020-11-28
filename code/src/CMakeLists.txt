cmake_minimum_required(VERSION 3.0)
project(Convertisseur VERSION 0.0.1 DESCRIPTION "ChiffreEnLettre ma library projet de C")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)



add_subdirectory(chiffreEnLettre)
add_subdirectory(utils)
add_subdirectory(array)


#find_package(ChiffreEnLettre)
#include_directories(${CHIFFREENLETTRE_INCLUDE_DIRS})
#link_directories(${CHIFFREENLETTRE_LIB_DIRS})

#find_package(Utils)
#include_directories(${UTILS_INCLUDE_DIRS})
#link_directories(${UTILS_LIB_DIRS})

#add_executable(main main.c main.h)

#include_directories(/lib/)
#link_directories(/lib/libyaml.so /usr/local/lib/dilacte)
#target_link_libraries(main libyaml.so)



