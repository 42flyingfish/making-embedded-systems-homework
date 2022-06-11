project(Drawing)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/src/draw.c
)

target_include_directories(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/src/include
)
