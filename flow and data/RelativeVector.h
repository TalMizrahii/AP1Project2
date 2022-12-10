#ifndef AP1PROJECT2_RELATIVEVECTOR_H
#define AP1PROJECT2_RELATIVEVECTOR_H

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class RelativeVector {

public:
    RelativeVector(vector<double> initValuesVector);

    RelativeVector();

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
    double distanceFromRelativeVec;
    int position = -1;
};



#endif //AP1PROJECT2_RELATIVEVECTOR_H



