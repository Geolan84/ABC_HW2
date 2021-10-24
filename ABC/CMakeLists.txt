cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(ABC LANGUAGES CXX)


set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        headers/Fish.h
        headers/Bird.h
        headers/Beast.h
        headers/Animal.h
        headers/Container.h

        # Sources
        sources/Fish.cpp
        sources/Bird.cpp
        sources/Beast.cpp
        sources/Animal.cpp
        sources/Container.cpp
        sources/main.cpp)

add_executable(ABC ${SOURCE_FILES})
