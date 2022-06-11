project(Console)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	console.h
	console.c
	consoleIo.h
	consoleIo.c
	consoleCommands.h
	consoleCommands.c
	version.h
	)
