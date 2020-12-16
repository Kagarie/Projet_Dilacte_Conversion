file(COPY yaml DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(numberToLetter)
add_subdirectory(utils)
add_subdirectory(array)

include_directories(${CMAKE_SOURCE_DIR}/src/code/utils)

add_executable(main main.h main.c)
target_link_libraries(main utils)
add_dependencies(main utils)

include_directories(${CMAKE_SOURCE_DIR}/src/code/array)
target_link_libraries(main array)
add_dependencies(main array)

include_directories(${CMAKE_SOURCE_DIR}/src/code/numberToLetter)
target_link_libraries(main numberToLetter)
add_dependencies(main numberToLetter)


INCLUDE_DIRECTORIES(/lib/)
LINK_DIRECTORIES(/lib/libyaml.so)
target_link_libraries(main libyaml.so)

enable_testing()

find_program(VALGRIND "valgrind")

file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")

foreach (FILENAME ${FILES})
    get_filename_component(SRC ${FILENAME} NAME)
    get_filename_component(TEST ${FILENAME} NAME_WE)
    add_executable(${TEST} ${SRC} main.h)
    add_dependencies(${TEST} numberToLetter)
    target_link_libraries(${TEST} main)
    if (VALGRIND)
        add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
        add_test("${TEST}[normal]" ./${TEST})
    else ()
        add_test("${TEST}" ./${TEST})
    endif ()
endforeach ()
