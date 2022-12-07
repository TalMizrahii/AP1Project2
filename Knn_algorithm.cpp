//
// Created by yuval on 12/7/22.
//

#include "Knn_algorithm.h"

#include <utility>

Knn_algorithm::~Knn_algorithm() = default;

Knn_algorithm::Knn_algorithm(vector<RelativeVector> cataloged_vectors1, string distance_by1,
                             vector<double> user_vector1,
                             int k_neighbors1) {
    setCataloged_vectors(std::move(cataloged_vectors1));
    setDistance_by(std::move(distance_by1));
    setUser_vector(std::move(user_vector1));
    setK_neighbors(k_neighbors1);
}

void Knn_algorithm::setCataloged_vectors(vector<RelativeVector> cataloged_vectors1) {
    this->cataloged_vectors = std::move(cataloged_vectors1);
}

void Knn_algorithm::setUser_vector(vector<double> user_vector1) {
    this->user_vector = std::move(user_vector1);
}

void Knn_algorithm::setDistance_by(string distance_by1) {
    this->distance_by = std::move(distance_by1);
}

void Knn_algorithm::setK_neighbors(int k_neighbors1) {
    this->k_neighbors = k_neighbors1;
}

int Knn_algorithm::getK_neighbors() const {
    return this->k_neighbors;
}

vector<double> Knn_algorithm::getUser_vector() {
    return this->user_vector;
}

string Knn_algorithm::getDistance_by() {
    return this->distance_by;
}

vector<RelativeVector> Knn_algorithm::getCataloged_vectors() {
    return this->cataloged_vectors;
}

void Knn_algorithm::calculate_distances() {
    for (int i = 0; i < getCataloged_vectors().size(); i++) {
        getCataloged_vectors()[i].setDistanceFromRelativeVec(
                this->distance.euclideanDistance(getCataloged_vectors()[i].getValuesVector(),
                                                 getUser_vector()));
    }
}
