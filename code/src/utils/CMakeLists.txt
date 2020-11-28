project(Utils C)
add_library(utils SHARED utils.c utils.h)
configure_file(utils.pc.in  utils.pc @ONLY)

install(
        TARGETS utils
        LIBRARY DESTINATION lib/dilacte/${CMAKE_BUILD_TYPE}
        ARCHIVE DESTINATION lib/dilacte/${CMAKE_BUILD_TYPE}
        RUNTIME DESTINATION bin/dilacte/${CMAKE_BUILD_TYPE}
)

install(
        FILES utils.h
        DESTINATION include/dilacte
)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/utils.pc.in
        ${CMAKE_CURRENT_BINARY_DIR}/utils.pc
        @ONLY
)
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/utils.pc
        DESTINATION share/pkgconfig/${CMAKE_BUILD_TYPE}
        COMPONENT "PkgConfig"
)


include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/UtilsConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/UtilsConfig.cmake
        INSTALL_DESTINATION cmake
)
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/UtilsConfig.cmake
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
    add_executable(${TEST} ${SRC} utils.h)
    # Précision de l'ordre de construction: le programme de test doit se faire
    # après la librairie
    add_dependencies(${TEST} utils)
    # Assemblage du programme de test avec la librairie chiffreEnLettre
    target_link_libraries(${TEST} utils)
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



