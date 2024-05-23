cmake_minimum_required(VERSION 3.28)
project(untilted C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# Tambahkan direktori header
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/path/to/SymbolicC++)

# Daftar file sumber
set(SOURCES
        src/calculator.c
        src/StackDinamis.c
        src/temperature.c
        src/tree.c
#        src/integral.cpp
        main.c
        src/gotoxy.c
)

# Jika ada file sumber C++ di SymbolicC++, tambahkan mereka ke dalam build system
file(GLOB SYMBOLICCXX_SOURCES ${PROJECT_SOURCE_DIR}/path/to/SymbolicC++/*.cpp)
list(APPEND SOURCES ${SYMBOLICCXX_SOURCES})

# Tambahkan eksekutabel dengan semua sumber yang ada
add_executable(untilted ${SOURCES})
