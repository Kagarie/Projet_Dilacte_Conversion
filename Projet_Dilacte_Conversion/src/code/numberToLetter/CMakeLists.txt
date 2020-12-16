add_library(numberToLetter SHARED numberToLetter.h numberToLetter.inc numberToLetter.c)

install(
        TARGETS numberToLetter
        LIBRARY DESTINATION lib/dilacte/${CMAKE_BUILD_TYPE}
        ARCHIVE DESTINATION lib/dilacte/${CMAKE_BUILD_TYPE}
        RUNTIME DESTINATION bin/dilacte/${CMAKE_BUILD_TYPE}
)

install(
        FILES numberToLetter.h
        DESTINATION include/dilacte/
)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/numberToLetter.pc.in
        ${CMAKE_CURRENT_BINARY_DIR}/numberToLetter.pc
        @ONLY
)
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/numberToLetter.pc
        DESTINATION share/pkgconfig/${CMAKE_BUILD_TYPE}
        COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/NumberToLetterConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/NumberToLetterConfig.cmake
        INSTALL_DESTINATION cmake
)
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/NumberToLetterConfig.cmake
        DESTINATION cmake
)

enable_testing()

find_program(VALGRIND "valgrind")

file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")

foreach (FILENAME ${FILES})
    get_filename_component(SRC ${FILENAME} NAME)
    get_filename_component(TEST ${FILENAME} NAME_WE)
    add_executable(${TEST} ${SRC} numberToLetter.h)
    add_dependencies(${TEST} numberToLetter)
    target_link_libraries(${TEST} numberToLetter)
    if (VALGRIND)
        add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
        add_test("${TEST}[normal]" ./${TEST})
    else ()
        add_test("${TEST}" ./${TEST})
    endif ()
endforeach ()