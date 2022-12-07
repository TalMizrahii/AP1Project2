cmake_minimum_required(VERSION 3.23)
project(AP1Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP1Project2
        RelativeVector.cpp
        RelativeVector.h
        FileReader.h
        FileReader.cpp
        Distances.h
        Distances.cpp
        main.cpp)