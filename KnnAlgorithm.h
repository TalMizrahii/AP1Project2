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

using namespace std;

class KnnAlgorithm {
public:
    // The constructor of the class.
    explicit KnnAlgorithm(vector<RelativeVector> cataloged_vectors, vector<double> user_vector,
                          int k_neighbors, AbstractDistance *calculation);
    // Setter for cataloged_vectors.
    void setCataloged_vectors(vector<RelativeVector> cataloged_vectors);
    // Setter for user_vector.
    void setUser_vector(vector<double> user_vector);
    // Setter for k_neighbors.
    void setK_neighbors(int k_neighbors);
    // Calculate the distances between the user_vector to all cataloged vectors(classified vectors).
    void calculate_distances();
    // Getter for k_neighbors.
    int getK_neighbors() const;
    // Getter for user_vector.
    vector<double> getUser_vector();
    // Getter for cataloged_vectors.
    vector<RelativeVector> getCataloged_vectors();
    // The Destructor of the class.
    ~KnnAlgorithm();

private:
    AbstractDistance *calc;
    // The user input vector.
    vector<double> user_vector;
    // The classified vectors.
    vector<RelativeVector> cataloged_vectors;
    // The k neighbors we got as argument to the program.
    int k_neighbors;
};

#endif //AP1PROJECT2_KNNALGORITHM_H