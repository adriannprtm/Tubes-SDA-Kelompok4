cmake_minimum_required(VERSION 3.28)
project(untitled C)

set(CMAKE_C_STANDARD 11)
set(SOURCES
        src/calculator.c
        src/StackDinamis.c
        src/temperature.c
        src/tree.c
#        src/gotoxy.c
)
set(HEADERS
        include/calculator.h
        include/StackDinamis.h
        include/temperature.h
        include/tree.h
)
add_executable(untitled main.c ${SOURCES} ${HEADERS})
