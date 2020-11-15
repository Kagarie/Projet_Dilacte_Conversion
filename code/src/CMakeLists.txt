#add_subdirectory(chiffreEnLettre)
#add_subdirectory(tabData)
add_subdirectory(utils)

INCLUDE_DIRECTORIES(/lib/)
LINK_DIRECTORIES(/lib/libyaml.so)

add_executable(main main.c main.h)
target_link_libraries(main libyaml.so)
target_link_libraries(main utils/libutils.so)

install(
        TARGETS main
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

install(
        FILES main.h
        DESTINATION include
)
