project(Array C)

include_directories(${CMAKE_SOURCE_DIR}/src/code/chiffreEnLettre)

add_library(array SHARED array.c array.h array.inc)
target_link_libraries(array chiffreEnLettre)
add_dependencies(array chiffreEnLettre)

install(
        TARGETS array
        LIBRARY DESTINATION lib/dilacte/${CMAKE_BUILD_TYPE}
        ARCHIVE DESTINATION lib/dilacte/${CMAKE_BUILD_TYPE}
        RUNTIME DESTINATION bin/dilacte/${CMAKE_BUILD_TYPE}
)

install(
        FILES array.h
        DESTINATION include/dilacte/
)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/array.pc.in
        ${CMAKE_CURRENT_BINARY_DIR}/array.pc
        @ONLY
)


include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/ArrayConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/ArrayConfig.cmake
        INSTALL_DESTINATION cmake
)
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/ArrayConfig.cmake
        DESTINATION cmake
)

enable_testing()

find_program(VALGRIND "valgrind")

file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")
foreach (FILENAME ${FILES})
    get_filename_component(SRC ${FILENAME} NAME)
    get_filename_component(TEST ${FILENAME} NAME_WE)
    add_executable(${TEST} ${SRC} array.h)
    add_dependencies(${TEST} chiffreEnLettre)
    target_link_libraries(${TEST} array)
    if (VALGRIND)
        add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
        add_test("${TEST}[normal]" ./${TEST})
    else ()
        add_test("${TEST}" ./${TEST})
    endif ()
endforeach ()
