//
// Created by tal on 12/8/22.
//

#ifndef AP1PROJECT2_CANBERRA_H
#define AP1PROJECT2_CANBERRA_H
#include "AbstractDistance.h"


class Canberra : public AbstractDistance{
public:
    // Calculates the Taxicab distance.
    double calculateDistance(vector<double> v1, vector<double> v2) override;

};
#endif //AP1PROJECT2_CANBERRA_H
