add_library(chiffreEnLettre SHARED chiffreEnLettre.h chiffreEnLettre.c chiffreEnLettre.inc)
install(TARGETS chiffreEnLettre DESTINATION lib)
file(GLOB
        headers
        *.hp
        )

install(FILES ${headers}
        DESTINATION include/${CMAKE_PROJECT_NAME})