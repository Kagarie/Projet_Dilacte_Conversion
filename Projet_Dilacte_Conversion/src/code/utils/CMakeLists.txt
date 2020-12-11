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
        ./utils.pc.in
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
        ./UtilsConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/UtilsConfig.cmake
        INSTALL_DESTINATION cmake
)
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/UtilsConfig.cmake
        DESTINATION cmake
)

enable_testing()

find_program(VALGRIND "valgrind")

file(GLOB FILES "./test-*.c")

foreach (FILENAME ${FILES})
    get_filename_component(SRC ${FILENAME} NAME)
    get_filename_component(TEST ${FILENAME} NAME_WE)
    add_executable(${TEST} ${SRC} utils.h)
    add_dependencies(${TEST} utils)
        target_link_libraries(${TEST} utils)
    if (VALGRIND)
        add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
        add_test("${TEST}[normal]" ./${TEST})
    else ()
        add_test("${TEST}" ./${TEST})
    endif ()
endforeach ()
