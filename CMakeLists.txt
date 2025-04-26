cmake_minimum_required(VERSION 3.31)
project(untitled43)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(Test)
set (SOURCE_FILES main.cpp
        Subject.h
        Observer.h
        Cella.h
        CellaFormula.h
        CellaSomma.h
        CellaValore.h
        CellaMassimo.h
        CellaMedia.h
        CellaMinimo.h
        CellaSomma.h)
add_executable(untitled43 main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(untitled43 core)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_library(NCURSES_LIB ncurses)
target_link_libraries(untitled43 ${NCURSES_LIB} core)