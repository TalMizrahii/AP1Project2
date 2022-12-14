#ifndef AP1PROJECT2_VALIDATIONS_H
#define AP1PROJECT2_VALIDATIONS_H

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * A validation class for vectors.
 */
class Validations {
public:
    // Checking if a string (representing a number) is a real number.
    bool isNumber(string s);

protected:
    // Checking if the number is a valid floating point number.
    bool validFloatingNumber(string string1, unsigned long &i);

    // Checking if a number is a valid negative number.
    bool validNegative(string string1, unsigned long &i);


};

#endif //AP1PROJECT2_VALIDATIONS_H
