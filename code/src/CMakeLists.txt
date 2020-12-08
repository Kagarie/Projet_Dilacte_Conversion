cmake_minimum_required(VERSION 3.0)
project(Convertisseur VERSION 0.0.1 DESCRIPTION "ChiffreEnLettre ma library projet de C")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

add_subdirectory(chiffreEnLettre)
add_subdirectory(utils)
add_subdirectory(array)

include_directories(${CMAKE_SOURCE_DIR}/utils)

add_executable(main main.h main.c)
target_link_libraries(main utils)
add_dependencies(main utils)

include_directories(${CMAKE_SOURCE_DIR}/array)
target_link_libraries(main array)
add_dependencies(main array)

include_directories(${CMAKE_SOURCE_DIR}/chiffreEnLettre)
target_link_libraries(main chiffreEnLettre)
add_dependencies(main chiffreEnLettre)


INCLUDE_DIRECTORIES(/lib/)
LINK_DIRECTORIES(/lib/libyaml.so)
target_link_libraries(main libyaml.so)

enable_testing()

find_program(VALGRIND "valgrind")

# Récupération dans la variable FILES des fichiers de test
file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")

# Pour tous les fichiers de test
foreach (FILENAME ${FILES})
    # Récupération dans la variable SRC du nom sans le préfixe du dossier
    get_filename_component(SRC ${FILENAME} NAME)
    # Récupération dans la variable TEST du nom sans le préfixe du dossier
    # et sans le suffixe
    get_filename_component(TEST ${FILENAME} NAME_WE)
    # Ajout d'un exécutable dépendant également de main.h
    add_executable(${TEST} ${SRC} main.h)
    # Précision de l'ordre de construction: le programme de test doit se faire
    # après la librairie
    add_dependencies(${TEST} chiffreEnLettre)
    # Assemblage du programme de test avec la librairie main
    target_link_libraries(${TEST} main)
    if (VALGRIND)
        # Ajout d'un test en utilisant valgrind
        add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
        # Ajout d'un test normal
        add_test("${TEST}[normal]" ./${TEST})
    else ()
        # Ajout d'un test simple
        add_test("${TEST}" ./${TEST})
    endif ()
endforeach ()