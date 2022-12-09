cmake_minimum_required(VERSION 3.23)
project(AP1Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP1Project2

        Minkowski.cpp
        Minkowski.h
        Euclidean.cpp
        Euclidean.h
        Taxicab.cpp
        Taxicab.h
        RelativeVector.cpp
        RelativeVector.h
        FileReader.h
        FileReader.cpp
        KnnAlgorithm.cpp
        KnnAlgorithm.h
        AbstractDistance.h
        AbstractDistance.cpp
        main.cpp Chebyshev.cpp Chebyshev.h Canberra.cpp Canberra.h)