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
    explicit Knn_algorithm(vector<RelativeVector> cataloged_vectors, string distance_by, vector<double> user_vector,
                           int k_neighbors);
    void setCataloged_vectors(vector<RelativeVector> cataloged_vectors);
    void setUser_vector(vector<double> user_vector);
    void setDistance_by(string distance_by);
    void setK_neighbors(int k_neighbors);
    void calculate_distances();
    int getK_neighbors() const;
    vector<double> getUser_vector();
    vector<RelativeVector> getCataloged_vectors();
    string getDistance_by();
    ~Knn_algorithm();

private:
    vector<double> user_vector;
    vector<RelativeVector> cataloged_vectors;
    Distances distance;
    string classification;
    string distance_by;
    int k_neighbors{};
};

#endif //AP1PROJECT2_KNN_ALGORITHM_H
