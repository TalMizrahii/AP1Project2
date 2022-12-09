//
// Created by yuval on 12/7/22.
//

#include "KnnAlgorithm.h"
#include <bits/stdc++.h>
#include <utility>

KnnAlgorithm::~KnnAlgorithm() = default;

KnnAlgorithm::KnnAlgorithm(vector<RelativeVector> cataloged_vectors1,
                           vector<double> user_vector1,
                           int k_neighbors1,
                           AbstractDistance *calculation){
    // Calling the setters.
    seCalc(calculation);
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

void KnnAlgorithm::seCalc(AbstractDistance *calculation1) {
    this->calc = calculation1;
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

AbstractDistance *KnnAlgorithm::getCalc() {
    return this->calc;
}

/**
 * The function check if the vectors we created have the same size.
 * @param v1 the vector we created from the user input.
 * @param v2 the vector we created from the user input.
 */
void KnnAlgorithm::size_Comparison(const vector<double> &v1, const vector<double> &v2) {
    // Checking if the vectors have the same size.
    if (v1.size() != v2.size()) {
        cout << "The vectors are not equally sized." << endl;
        exit(-1);
    }
}

void KnnAlgorithm::calculate_distances() {
    // This for loop calc the distance between user_vector(user input) to all the cataloged vectors.
    for (int i = 0; i < getCataloged_vectors().size(); i++) {
        // Checking if the vectors in the same size.
        size_Comparison(getCataloged_vectors()[i].getValuesVector(),getUser_vector());
        getCataloged_vectors()[i].setDistanceFromRelativeVec(
                this->calc->calculateDistance(getCataloged_vectors()[i].getValuesVector(),
                                                 getUser_vector()));
    }
}

bool KnnAlgorithm::compareRelativeVector(RelativeVector i1, RelativeVector i2) {
    return (i1.getDistanceFromRelativeVec() < i2.getDistanceFromRelativeVec());
}

vector<RelativeVector> KnnAlgorithm::sortingAndGettingK(){
    sort(getCataloged_vectors().begin(),getCataloged_vectors().end(), compareRelativeVector);
    vector<RelativeVector> kRelativeVectors;
    for (int i = 0; i < getK_neighbors(); i++) {
        kRelativeVectors.push_back(getCataloged_vectors()[i]);
    }
    return kRelativeVectors;
}

string KnnAlgorithm::classificationUserVec(){
    calculate_distances();
    vector<RelativeVector> nearestK = sortingAndGettingK();

}






