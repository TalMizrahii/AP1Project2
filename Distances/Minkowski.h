#ifndef AP1PROJECT2_MINKOWSKI_H
#define AP1PROJECT2_MINKOWSKI_H
#include "AbstractDistance.h"

class Minkowski: public AbstractDistance{
public:
    // Calculates the Euclidean distance.
    double calculateDistance(vector<double> v1, vector<double> v2) override;
    // Calculates the minkowski distance.
    double minkowskiDistance(vector<double> v1, vector<double> v2, double p);

};
#endif //AP1PROJECT2_MINKOWSKI_H
