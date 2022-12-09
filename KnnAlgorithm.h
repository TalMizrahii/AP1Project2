//
// Created by yuval on 12/7/22.
//

#ifndef AP1PROJECT2_KNNALGORITHM_H
#define AP1PROJECT2_KNNALGORITHM_H

#include <cstdlib>
#include <vector>
#include <string>
#include "RelativeVector.h"
#include "AbstractDistance.h"
#include <bits/stdc++.h>
#include <utility>

using namespace std;

class KnnAlgorithm {
public:
    // The constructor of the class.
    explicit KnnAlgorithm(vector<RelativeVector *> cataloged_vectors, vector<double> user_vector,
                          int k_neighbors, AbstractDistance *calculation);

    // Setter for cataloged_vectors.
    void setCataloged_vectors(vector<RelativeVector *> cataloged_vectors);

    // Setter for userVector.
    void setUserVector(vector<double> user_vector);

    // Setter for Calc.
    void seCalc(AbstractDistance *calculation1);

    // Setter for k_neighbors.
    void setKNeighbors(int k_neighbors);

    // Calculate the distances between the userVector to all cataloged vectors(classified vectors).
    void calculateDistances();

    // Getter for k_neighbors.
    int getKNeighbors() const;

    // Getter for userVector.
    vector<double> getUserVector();

    // Getter for cataloged_vectors.
    vector<RelativeVector *> getCatalogedVectors();

    // Getter for calc.
    AbstractDistance *getCalc();


    // Check validation of the vectors.
    void sizeComparison(const vector<double> &v1, const vector<double> &v2);

    // Compares two vectors according to their distance from the userVector.
//    static bool compareRelativeVector(RelativeVector *i1, RelativeVector *i2);

    vector<RelativeVector *> sortingAndGettingK();

    // The Destructor of the class.
    ~KnnAlgorithm();

    string classificationUserVec();



private:
    AbstractDistance *calc;
    // The user input vector.
    vector<double> userVector;
    // The classified vectors.
    vector<RelativeVector *> catalogedVectors;
    // The k neighbors we got as argument to the program.
    int kNeighbors;


};

#endif //AP1PROJECT2_KNNALGORITHM_H
