//
// Created by yuval on 12/7/22.
//

#include "KnnAlgorithm.h"
#include <bits/stdc++.h>
#include <utility>
#include "RelativeVector.h"

KnnAlgorithm::~KnnAlgorithm() = default;

KnnAlgorithm::KnnAlgorithm(vector<RelativeVector *> cataloged_vectors1,
                           vector<double> user_vector1,
                           int k_neighbors1,
                           AbstractDistance *calculation) {
    // Calling the setters.
    seCalc(calculation);
    setCataloged_vectors(std::move(cataloged_vectors1));
    setUserVector(std::move(user_vector1));
    setKNeighbors(k_neighbors1);
}

/**
 * Set cataloged_vectors.
 * @param cataloged_vectors1
 */
void KnnAlgorithm::setCataloged_vectors(vector<RelativeVector *> cataloged_vectors1) {
    this->cataloged_vectors = std::move(cataloged_vectors1);
}

void KnnAlgorithm::setUserVector(vector<double> user_vector1) {
    // Set user_vector.
    this->user_vector = std::move(user_vector1);
}


void KnnAlgorithm::setKNeighbors(int k_neighbors1) {
    // Set k_neighbors.
    this->k_neighbors = k_neighbors1;
}

void KnnAlgorithm::seCalc(AbstractDistance *calculation1) {
    this->calc = calculation1;
}

int KnnAlgorithm::getKNeighbors() const {
    // Get k_neighbors.
    return this->k_neighbors;
}

vector<double> KnnAlgorithm::getUser_vector() {
    // Get user_vector.
    return this->user_vector;
}

vector<RelativeVector *> KnnAlgorithm::getCatalogedVectors() {
    // Get cataloged_vectors.
    return cataloged_vectors;
}

AbstractDistance *KnnAlgorithm::getCalc() {
    return this->calc;
}

/**
 * The function check if the vectors we created have the same size.
 * @param v1 the vector we created from the user input.
 * @param v2 the vector we created from the user input.
 */
void KnnAlgorithm::sizeComparison(const vector<double> &v1, const vector<double> &v2) {
    // Checking if the vectors have the same size.
    if (v1.size() != v2.size()) {
        cout << "The vectors are not equally sized." << endl;
        exit(-1);
    }
}

void KnnAlgorithm::calculateDistances() {
    // This for loop calc the distance between user_vector(user input) to all the cataloged vectors.
    for (int i = 0; i < getCatalogedVectors().size(); i++) {
        // Checking if the vectors in the same size.
        sizeComparison(getCatalogedVectors()[i]->getValuesVector(), getUser_vector());
        double result = getCalc()->calculateDistance(getCatalogedVectors()[i]->getValuesVector(), getUser_vector());
        getCatalogedVectors()[i]->setDistanceFromRelativeVec(result);
//        cout << getCatalogedVectors()[i]->getDistanceFromRelativeVec() << endl;
    }
}

bool compareRelativeVector(RelativeVector *i1, RelativeVector *i2) {
    return (i1->getDistanceFromRelativeVec() < i2->getDistanceFromRelativeVec());
}

vector<RelativeVector *> KnnAlgorithm::sortingAndGettingK() {
    vector<RelativeVector *> knn = getCatalogedVectors();
    sort(knn.begin(), knn.end(), compareRelativeVector);
    vector<RelativeVector*> kRelativeVectors;
    setCataloged_vectors(knn);
    for (int i = 0; i < getKNeighbors(); i++) {
        cout << knn[i]->getDistanceFromRelativeVec() << endl;
        kRelativeVectors.push_back(knn[i]);
    }
    return kRelativeVectors;
}

string KnnAlgorithm::classificationUserVec() {
    calculateDistances();
    vector<RelativeVector *> nearestK = sortingAndGettingK();
//        cout << "oin" << endl;
//    for (int i = 0; i < nearestK.size(); ++i) {
//        cout << nearestK[i]->getDistanceFromRelativeVec() << endl;
//    }
    return "";
}