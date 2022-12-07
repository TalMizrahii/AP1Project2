//
// Created by tal on 12/7/22.
//

#ifndef AP1PROJECT2_RELATIVEVECTOR_H
#define AP1PROJECT2_RELATIVEVECTOR_H

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class RelativeVector {

public:
    explicit RelativeVector(vector<double> initValuesVector);

    ~RelativeVector();

    void setValuesVector(vector<double> newValuesVector);

    void setClassification(string newClassification);

    void setDistanceFromRelativeVec(double newDistanceFromRelativeVec);

    void setPosition(int newPosition);

    vector<double> getValuesVector();

    string getClassification();

    double getDistanceFromRelativeVec();

    int getPosition();

private:
    vector<double> valuesVector;
    string classification;
    double distanceFromRelativeVec = -1;
    int position = -1;
};

#endif //AP1PROJECT2_RELATIVEVECTOR_H



