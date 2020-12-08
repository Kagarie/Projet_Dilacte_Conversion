project(ChiffreEnLettre C)

add_library(chiffreEnLettre SHARED chiffreEnLettre.h chiffreEnLettre.inc chiffreEnLettre.c)

install(
        TARGETS chiffreEnLettre
        LIBRARY DESTINATION lib/dilacte/${CMAKE_BUILD_TYPE}
        ARCHIVE DESTINATION lib/dilacte/${CMAKE_BUILD_TYPE}
        RUNTIME DESTINATION bin/dilacte/${CMAKE_BUILD_TYPE}
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

file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")

foreach (FILENAME ${FILES})
    get_filename_component(SRC ${FILENAME} NAME)
    get_filename_component(TEST ${FILENAME} NAME_WE)
    add_executable(${TEST} ${SRC} chiffreEnLettre.h)
    add_dependencies(${TEST} chiffreEnLettre)
    target_link_libraries(${TEST} chiffreEnLettre)
    if (VALGRIND)
        add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
        add_test("${TEST}[normal]" ./${TEST})
    else ()
        add_test("${TEST}" ./${TEST})
    endif ()
endforeach ()