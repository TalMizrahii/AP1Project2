#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Distances.h"
#include <cstdlib>

using namespace std;

/**
 * The function check if the input has negative sign that the user enters is in a valid format.
 *
 * @param string1 the user input string.
 * @param i the for loop counter.
 * @return return false if isn't valid and true if valid
 * (we get the loop counter by reference because if valid we want to continue).
 */
bool validNegative(string string1, unsigned long &i) {
    // If the sign is not valid by format, reject.
    if (i == string1.length() - 1
        || (string1[i] == '-'
            && string1[i - 1] != ' ')) {
        return false;
    }
    // Want to get ahead in the for loop.
    i++;
    return true;
}

/**
 * The function check if the input has '.' sign that the user enters is in a valid format(floating point format).
 *
 * @param string1 the user input string.
 * @param i the for loop counter.
 * @return return false if isn't valid and true if valid
 * (we get the loop counter by reference because if valid we want to continue).
 */
bool validFloatingNumber(string string1, unsigned long &i) {
    // If we have '.' we must get a number in the next char, otherwise not in format,
    // And checking if not accessing out of scoping our array.
    if ((i == string1.length() - 1)
        || (isdigit(string1[i + 1]) == false
            || isdigit(string1[i - 1]) == false)) {
        return false;
    }
    // Checking if there are any chars in the floating point string that is not a digit.
    for (unsigned long j = i + 1; j < string1.length(); j++) {
        // If we have space we the format is valid.
        if (string1[j] == ' ') {
            break;
            // If after the point there any char that is not a digit return false (not a valid floating format).
        } else if (isdigit(string1[j]) == false) {
            return false;
        }
    }
    // Want to get ahead in the for loop.
    i++;
    return true;
}


/**
 * Checking if the user input is in the right format.
 * @param s a string that the user entered.
 * @return boolean, True if the the string in the right format False otherwise.
 */
bool isNumber(string s) {
    unsigned long i = 0;
    // Check if the first or last char in the input is ' ' and if the first char is '-'.
    if ((isdigit(s[i]) == false && s[i] != '-')
        || isdigit(s[s.length() - 1]) == false) {
        return false;
    }
    // Check each char of the user input.
    for (i = 1; i < s.length(); i++) {
        // Checking if the user input has 2 spaces neighbors.
        if ((s[i] == ' ' && s[i - 1] == ' ')) {
            return false;
        }
        // Checking if there is a space , if we have only 1 space, the format is still correct.
        if (s[i] == ' ') {
            continue;
        }
        // Checking if the user input a valid floating point number.
        if (s[i] == '.' && !validFloatingNumber(s, i)) {
            return false;
        }
        // Checking if the chars are in valid negative format
        if (s[i] == '-' && !validNegative(s, i)) {
            return false;
        }
        // Checking if the char is a digit.
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}


/**
 * Creating a vector from user's input and checking if its valid.
 * @return Return a valid vector by the specified format of the task.
 */
vector<double> insert_To_Vector() {
    string input;
    double number;
    vector<double> vector;
    // Using a stream function to get a string from the user.
    getline(cin, input);
    // Send the string to be checked for validation.
    if (!isNumber(input)) {
        cout << "Illegal format" << endl;
        exit(0);
    }
    // Creating a vector from the user input string.
    istringstream vectorStream(input);
    while (vectorStream >> number) {
        vector.push_back(number);
    }
    return vector;
}

/**
 * The function check if the vectors we created have the same size.
 * @param v1 the vector we created from the user input.
 * @param v2 the vector we created from the user input.
 */
void size_Comparison(const vector<double> &v1, const vector<double> &v2) {
    // Checking if the vectors have the same size.
    if (v1.size() != v2.size()) {
        cout << "The vectors are not equally sized." << endl;
        exit(0);
    }
}

/**
 * This is the main function of the program, creating 2 vectors and checking validation.
 * @return return 0 if the program run without issues.
 */
int main() {
    // Creating two vectors from the user's inputs.
    vector<double> vector1 = insert_To_Vector();
    vector<double> vector2 = insert_To_Vector();
    // Calling a function that check if the vectors have the same size.
    size_Comparison(vector1, vector2);
    // Creating a Distance instance.
    Distances D;
    // Printing all distances calculations.
    D.printAll(vector1, vector2);
    return 0;
}