#ifndef AP1PROJECT_DISTANCES_H
#define AP1PROJECT_DISTANCES_H

#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>


/**
 * This class calculate the distance between two vectors using different distance algorithms.
 */
using namespace std;

class AbstractDistance {

public:
    virtual double calculateDistance(vector<double> v1, vector<double> v2) = 0;

};

#endif //AP1PROJECT_DISTANCES_H