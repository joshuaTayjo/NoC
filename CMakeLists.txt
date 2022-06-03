cmake_minimum_required(VERSION 3.14)
project(NoC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
IF(APPLE)
    SET(CMAKE_OSX_ARCHITECTURES "x86_64;" CACHE STRING "Build architectures for Mac OS X" FORCE)
ENDIF(APPLE)
set(SOURCE_FILES main.cpp Walker.cpp Walker.h PVector.cpp PVector.h Mover.cpp Mover.h Liquid.cpp Liquid.h Attractor.cpp Attractor.h Utils.cpp Utils.h)
add_executable(NoC ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(NoC sfml-system sfml-window sfml-graphics sfml-audio sfml-network)