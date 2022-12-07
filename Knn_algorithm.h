//
// Created by yuval on 12/7/22.
//

#ifndef AP1PROJECT2_KNN_ALGORITHM_H
#define AP1PROJECT2_KNN_ALGORITHM_H

#include <cstdlib>
#include <vector>
#include <string>
#include "RelativeVector.h"
#include "Distances.h"

using namespace std;

class Knn_algorithm {
public:
    // The constructor of the class.
    explicit Knn_algorithm(vector<RelativeVector> cataloged_vectors, string distance_by, vector<double> user_vector,
                           int k_neighbors);
    // Setter for cataloged_vectors.
    void setCataloged_vectors(vector<RelativeVector> cataloged_vectors);
    // Setter for user_vector.
    void setUser_vector(vector<double> user_vector);
    // Setter for distance_by.
    void setDistance_by(string distance_by);
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
    // Getter for distance_by.
    string getDistance_by();
    // The Destructor of the class.
    ~Knn_algorithm();

private:
    // The user input vector.
    vector<double> user_vector;
    // The classified vectors.
    vector<RelativeVector> cataloged_vectors;
    Distances distance;
    string classification;
    string distance_by;
    // The k neighbors we got as argument to the program.
    int k_neighbors{};
};

#endif //AP1PROJECT2_KNN_ALGORITHM_H
