cmake_minimum_required(VERSION 3.0)
project(Convertisseur_chiffre)

INCLUDE_DIRECTORIES(/lib/)
LINK_DIRECTORIES(/lib/libyaml.so)
add_executable(testLecture testLecture.c)

add_executable(convertisseur  convertisseur.c convertisseur.h)

target_link_libraries(testLecture libyaml.so)


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