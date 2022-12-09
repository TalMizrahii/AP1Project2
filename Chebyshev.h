//
// Created by tal on 12/8/22.
//

#ifndef AP1PROJECT2_CHEBYSHEV_H
#define AP1PROJECT2_CHEBYSHEV_H
#include "AbstractDistance.h"

/**
 * Calculating the Chebyshev distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Chebyshev distance between the two vectors.
 */
class Chebyshev : public AbstractDistance{
public:
    // Calculates the Chebyshev distance.
    double calculateDistance(vector<double> v1, vector<double> v2) override;

};
#endif //AP1PROJECT2_CHEBYSHEV_H
