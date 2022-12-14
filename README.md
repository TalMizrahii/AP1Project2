<h1 align="center">
  <br>
  <a href="https://github.com/TalMizrahii/AP1Project"><img src="https://img.icons8.com/color/344/c-plus-plus-logo.png" alt="C++" width="200"></a>
  <br>
  Advanced-Programming-1
  <br>
</h1>

<h4 align="center">This github repository is for the assignments given in Advanced Programming 1 course, Bar Ilan University.


<p align="center">
  <a href="#description">Description</a> •
  <a href="#implementation">Implementation</a> •
  <a href="#dependencies">Dependencies</a> •
  <a href="#installing-and-executing">Installing And Executing</a> •
  <a href="#authors">Authors</a> 
</p>

## Description
In this program, we asked to calculate the [KNN](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm) (K nearest neighbors) to a given vector.

The program receives 3 arguments:
* 1. The number K for the KNN algorithm.
* 2. The path to the database (explained later).
* 3. The distance calculation was wanted to be used in the KNN algorithm.
  
The third argument (The distance calculation) is interpreted as:
  * MUN - [Taxicab geometry](https://en.wikipedia.org/wiki/Taxicab_geometry)
  * AUC - [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance)
  * CHB - [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance)
  * CAN - [Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance)
  * MIN - [Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance)
  
  
 We use a given database named "datasets", containing .cvs files. each row in a file represents a vector of doubles. The last cell in the row represents the classification of the vector. 

We created a RelativeVector class, which contains the vector of doubles and the classification for each row. We calculated the KNN using a hash map and returned the resulting classification.

At the beginning of the program, the user needs to enter a vector that he wants to classify. This vector has a format, and if the user doesn't follow it the program will print "Illegal format" and will shut down the program. If the program won't find the .csv file, it will print "NO FILE" and will also shut down. 



## Implementation

## Dependencies

* The program tested for linux machines.
* Compiled with g++.

## Installing And Executing

To clone and run this application, you'll need [Git](https://git-scm.com) installed on your computer. From your command line:

```bash
# Clone this repository.
$ git clone https://github.com/TalMizrahii/AP1Project

# Go into the repository.
$ cd AP1Project

# Compile using makefile.
$ make
```

```bash
# Run the program on Linux:
$ ./a.out
```

```bash
# Run the program on Windows:
$ a.out
```

```bash
# After running, clean all unnecessary files.
$ make clean
```

## Authors
* [@Yuval Arbel](https://github.com/YuvalArbel1)
* [@Tal Mizrahi](https://github.com/TalMizrahii)

