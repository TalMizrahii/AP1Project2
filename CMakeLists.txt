cmake_minimum_required(VERSION 3.23)
project(AP1Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP1Project2
        Distances/Minkowski.cpp
        Distances/Minkowski.h
        Distances/Euclidean.cpp
        Distances/Euclidean.h
        Distances/Taxicab.cpp
        Distances/Taxicab.h
        "flow and data/RelativeVector.cpp"
        "flow and data/RelativeVector.h"
        "flow and data/FileReader.h"
        "flow and data/FileReader.cpp"
        Distances/AbstractDistance.h
        Distances/AbstractDistance.cpp
        main.cpp Distances/Chebyshev.cpp Distances/Chebyshev.h Distances/Canberra.cpp Distances/Canberra.h)