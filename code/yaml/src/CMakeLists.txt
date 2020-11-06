cmake_minimum_required(VERSION 3.0)
project(Dialecte C)
INCLUDE_DIRECTORIES(/lib/)
LINK_DIRECTORIES(/lib/libyaml.so)

add_executable(testLecture testLecture.c)
target_link_libraries(testLecture libyaml.so)
