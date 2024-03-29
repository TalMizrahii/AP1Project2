#ifndef AP1PROJECT2_EUCLIDEAN_H
#define AP1PROJECT2_EUCLIDEAN_H

#include "AbstractDistance.h"

/**
 * A distance calculation class using Euclidean algorithm.
 */
class Euclidean : public AbstractDistance {
public:
    // Calculates the Euclidean distance.
    double calculateDistance(vector<double> v1, vector<double> v2) override;

};

#endif //AP1PROJECT2_EUCLIDEAN_H
