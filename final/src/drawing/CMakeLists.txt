project(drawing)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
draw.h
draw.c
	)
