add_library(tabData SHARED tabData.c tabData.h tabData.inc)
install(TARGETS tabData DESTINATION lib)
file(GLOB
        headers
        *.h
        )

install(FILES ${headers}
        DESTINATION include/${CMAKE_PROJECT_NAME})