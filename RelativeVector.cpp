//
// Created by tal on 12/7/22.
//

#include "RelativeVector.h"

#include <utility>

RelativeVector::RelativeVector(vector<double> initValuesVector) {
    setValuesVector(std::move(initValuesVector));
}

RelativeVector::~RelativeVector() = default;

void RelativeVector::setValuesVector(vector<double> newValuesVector) {
    this->valuesVector = std::move(newValuesVector);
}

void RelativeVector::setClassification(string newClassification) {
    this->classification = std::move(newClassification);
}

void RelativeVector::setDistanceFromRelativeVec(double newDistanceFromRelativeVec) {
    this->distanceFromRelativeVec = newDistanceFromRelativeVec;
}

void RelativeVector::setPosition(int newPosition) {
    this->position = newPosition;
}

vector<double> RelativeVector::getValuesVector() {
    return this->valuesVector;
}

string RelativeVector::getClassification() {
    return this->classification;
}

double RelativeVector::getDistanceFromRelativeVec() {
    return this->distanceFromRelativeVec;
}

int RelativeVector::getPosition() {
    return this->position;
}




