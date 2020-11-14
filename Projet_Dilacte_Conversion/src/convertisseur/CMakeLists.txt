cmake_minimum_required(VERSION 3.0)
project(Projet_Dilacte_Conversion)

add_executable(convertisseur  convertisseur.c convertisseur.h convertisseur.inc)

install(
    TARGETS convertisseur
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(
    FILES convertisseur.h
    DESTINATION include
)
