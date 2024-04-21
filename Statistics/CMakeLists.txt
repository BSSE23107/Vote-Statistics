# cmake_minimum_required(VERSION <specify CMake version here>)
project(Statistics)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Statistics
        Person.cpp
        Person.h
        persons_data.json
        Voter.cpp
        Voter.h)
