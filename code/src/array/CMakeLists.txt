include(GNUInstallDirs)
add_library(tabData SHARED tabData.inc tabData.h tabData.c)
set_target_properties(tabData PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1 PUBLIC_HEADER chiffreEnLettre.h)
configure_file(../utils/array.pc.in ../utils/array.pc @ONLY)


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
    # Ajout d'un exécutable dépendant également de tabData.h
    add_executable(${TEST} ${SRC} array.h)
    # Précision de l'ordre de construction: le programme de test doit se faire
    # après la librairie
    add_dependencies(${TEST} chiffreEnLettre)
    # Assemblage du programme de test avec la librairie tabData
    target_link_libraries(${TEST} array)
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