# on créait une varaible SRCS qui contient les feuilles chiffreEnLettre.insc/.h/.c
set(SRCS chiffreEnLettre.c)
set(HEADERS chiffreEnLettre.h)
set(INCS chiffreEnLettre.inc)
add_library(chiffreEnLettre SHARED  ${SRCS} ${HEADERS} ${INCS})

configure_file(chiffreEnLettre.pc.in chiffreEnLettre.pc @ONLY)
set_target_properties(chiffreEnLettre PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1 PUBLIC_HEADER chiffreEnLettre.h)
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
    # Ajout d'un exécutable dépendant également de chiffreEnLettre.h
    add_executable(${TEST} ${SRC} chiffreEnLettre.h)
    # Précision de l'ordre de construction: le programme de test doit se faire
    # après la librairie
    add_dependencies(${TEST} chiffreEnLettre)
    # Assemblage du programme de test avec la librairie chiffreEnLettre
    target_link_libraries(${TEST} chiffreEnLettre)
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

install(
        TARGETS chiffreEnLettre
        LIBRARY DESTINATION lib/dilacte
        ARCHIVE DESTINATION lib/dilacte
        RUNTIME DESTINATION bin/dilacte
)

install(
        FILES chiffreEnLettre.h
        DESTINATION include/dilacte/
)