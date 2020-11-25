project(ChiffreEnLettre C)

add_library(chiffreEnLettre SHARED chiffreEnLettre.h chiffreEnLettre.inc chiffreEnLettre.c)

install(
        TARGETS chiffreEnLettre
        LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE}
        ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE}
        RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE}
)

install(
        FILES chiffreEnLettre.h
        DESTINATION include/dilacte/
)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/chiffreEnLettre.pc.in
        ${CMAKE_CURRENT_BINARY_DIR}/chiffreEnLettre.pc
        @ONLY
)
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/chiffreEnLettre.pc
        DESTINATION share/pkgconfig/${CMAKE_BUILD_TYPE}
        COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/ChiffreEnLettreConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/ChiffreEnLettreConfig.cmake
        INSTALL_DESTINATION cmake
)
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/ChiffreEnLettreConfig.cmake
        DESTINATION cmake
)

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

