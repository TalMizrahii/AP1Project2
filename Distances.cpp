#include "Distances.h"

/**
 * A constructor for the class.
 */
Distances::Distances() = default;

/**
 * Calculating the Euclidean distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Euclidean distance between the two vectors.
 */
double Distances::euclideanDistance(vector<double> v1, vector<double> v2) {
    // Minkowski Distance with p = 2 is exactly the value of Euclidean distance.
    return minkowskiDistance(v1, v2, 2);
}

/**
 * Calculating the Taxicab Geometry distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Taxicab Geometry distance between the two vectors.
 */
double Distances::taxicabDistance(vector<double> v1, vector<double> v2) {
    // Minkowski Distance with p = 1 is exactly the value of Taxicab distance.
    return minkowskiDistance(v1, v2, 1);
}

/**
 * Calculating the Chebyshev distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Chebyshev distance between the two vectors.
 */
double Distances::chebyshevDistance(vector<double> v1, vector<double> v2) {
    // Setting the maximum to the first couple of points.
    double max = fabs(v1[0] - v2[0]);
    double temp;
    // Iterating over the indexes in each vector.
    for (unsigned long i = 1; i < v1.size(); i++) {
        // Setting the temp to be the value of distance between v1[i] to v2[i].
        temp = fabs(v1[i] - v2[i]);
        // If temp is bigger than max, max is now temp.
        if (temp > max)
            max = temp;
    }
    // Return the maximum value.
    return max;
}

/**
 * Calculating the Canberra distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Canberra distance between the two vectors.
 */
double Distances::canberraDistance(vector<double> v1, vector<double> v2) {
    // Setting the result to 0.
    double result = 0;
    // Iterating over the indexes in each vector.
    for (unsigned long i = 0; i < v1.size(); i++) {
        // Avoiding division by 0.
        if (v1[i] == 0 && v2[i] == 0) {
            continue;
        }
        // Calculating the subtraction between them in absolute value, dividing by each index in absolut value,
        // and adding to result.
        result += fabs(v1[i] - v2[i]) / (fabs(v1[i]) + fabs(v2[i]));
    }
    // Returning the result.
    return result;
}

/**
 * Calculating the Minkowski distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @param p the constant value in the algorithm.
 * @return the Minkowski distance between the two vectors.
 */
double Distances::minkowskiDistance(vector<double> v1, vector<double> v2, double p) {
    // Setting the result to 0.
    double result = 0;
    // Iterating over the indexes in each vector.
    for (unsigned long i = 0; i < v1.size(); i++) {
        // Calculating the subtraction between them in absolute value, raising to the power of 2 and adding to result.
        result += pow(fabs(v1[i] - v2[i]), p);
    }
    // Returning the result to the power of p^-1.
    return pow(result, 1.0 / p);
}

/**
 * Printing a double representing a result of a distance calculation by the format requested.
 * @param result a result of a distance calculation.
 */
void Distances::printDistance(double result) {
    // If the floor of a double is equal to its ceiling, it's an integer.
    if (floor(result) == ceil(result)) {
        printf("%.1lf\n", result);
    } else {
        // It's not an integer, so print it like a double.
        printf("%lf\n", result);
    }
}

/**
 * Printing all calculations between two vectors made by this class.
 * @param v1 the first vector.
 * @param v2 the second vector.
 */
void Distances::printAll(const vector<double> &d1, const vector<double> &d2) {
    printDistance(euclideanDistance(d1, d2));
    printDistance(taxicabDistance(d1, d2));
    printDistance(chebyshevDistance(d1, d2));
    printDistance(canberraDistance(d1, d2));
    printDistance(minkowskiDistance(d1, d2, 2));
}

/**
 * A destructor for this class.
 */
Distances::~Distances() = default;
