//
// Created by yuval on 12/7/22.
//

#include "KnnAlgorithm.h"

#include <utility>

KnnAlgorithm::~KnnAlgorithm() = default;

KnnAlgorithm::KnnAlgorithm(vector<RelativeVector> cataloged_vectors1,
                           vector<double> user_vector1,
                           int k_neighbors1,
                           AbstractDistance *calculation){
    // Calling the setters.
    calc = calculation;
    setCataloged_vectors(std::move(cataloged_vectors1));
    setUser_vector(std::move(user_vector1));
    setK_neighbors(k_neighbors1);
}

/**
 * Set cataloged_vectors.
 * @param cataloged_vectors1
 */
void KnnAlgorithm::setCataloged_vectors(vector<RelativeVector> cataloged_vectors1) {
    this->cataloged_vectors = std::move(cataloged_vectors1);
}

void KnnAlgorithm::setUser_vector(vector<double> user_vector1) {
    // Set user_vector.
     this->user_vector = std::move(user_vector1);
}



void KnnAlgorithm::setK_neighbors(int k_neighbors1) {
    // Set k_neighbors.
    this->k_neighbors = k_neighbors1;
}

int KnnAlgorithm::getK_neighbors() const {
    // Get k_neighbors.
    return this->k_neighbors;
}

vector<double> KnnAlgorithm::getUser_vector() {
    // Get user_vector.
    return this->user_vector;
}

vector<RelativeVector> KnnAlgorithm::getCataloged_vectors() {
    // Get cataloged_vectors.
    return this->cataloged_vectors;
}

void KnnAlgorithm::calculate_distances() {
    // This for loop calc the distance between user_vector(user input) to all the cataloged vectors.
    for (int i = 0; i < getCataloged_vectors().size(); i++) {
        getCataloged_vectors()[i].setDistanceFromRelativeVec(
                this->calc->calculateDistance(getCataloged_vectors()[i].getValuesVector(),
                                                 getUser_vector()));
    }
}
