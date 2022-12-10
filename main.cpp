#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "flow and data/FileReader.h"
# include "Distances/Minkowski.h"
# include "Distances/Euclidean.h"
# include "Distances/Taxicab.h"
# include "Distances/Canberra.h"
# include "Distances/Chebyshev.h"
#include "flow and data/KnnAlgorithm.h"

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


vector<string> extract_argc(char *argcArray[]) {
    // As we know the argc[0] is the program name, and by the format argc[1] is the k neighbors.
    string neighbors = argcArray[1];
    // As we know the argc[0] is the program name, and by the format argc[2] is the file/path.
    string path = argcArray[2];
    // As we know the argc[0] is the program name, and by the format argc[3] is the distance_algorithm.
    string distance_algorithm = argcArray[3];
    // Checking if the k neighbors is legal.
    for (char neighbor: neighbors) {
        if (!isdigit(neighbor) || neighbors[0] == '0') {
            cout << "Illegal Format." << endl;
            exit(0);
        }
    }
    // Creating a string vector
    vector<string> vector;
    vector.push_back(neighbors);
    vector.push_back(path);
    vector.push_back(distance_algorithm);
    return vector;
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
        exit(-1);
    }
    // Creating a vector from the user input string.
    istringstream vectorStream(input);
    while (vectorStream >> number) {
        vector.push_back(number);
    }
    return vector;
}



/**
 * returning the distance object (on the heap) as the user specified.
 * @param distanceSpec The user's request.
 * @return The instance of the distance.
 */
AbstractDistance *distanceCreator(const string &distanceSpec) {
    // Return the Euclidean distance.
    if (distanceSpec == "AUC") {
        auto *euc = new Euclidean();
        return euc;
    }
    // Return the Taxicab distance.
    if (distanceSpec == "MAN") {
        auto *man = new Taxicab();
        return man;
    }
    // Return the Chebyshev distance.
    if (distanceSpec == "CHB") {
        auto *chb = new Chebyshev();
        return chb;
    }
    // Return the Canberra distance.
    if (distanceSpec == "CAN") {
        auto *can = new Canberra();
        return can;
    }
    // Return the Minkowski distance.
    if (distanceSpec == "MIN") {
        auto *min = new Minkowski();
        return min;
    }
    // If no valid option was chosen, exit.
    cout << "Illegal Format" << endl;
    exit(-1);
}

/**
 * This is the main function of the program, creating 2 vectors and checking validation.
 * @return return 0 if the program run without issues.
 */
int main(int args, char *argv[]) {
    vector<string> argc_vector = extract_argc(argv);

    int kNeighbors = stoi(argc_vector[0]);
    string path = argc_vector[1];
    string distance_algorithm = argc_vector[2];
    // Creating one vector from the user's inputs.
    vector<double> vector1 = insert_To_Vector();

    AbstractDistance *disCalc = distanceCreator(distance_algorithm);
    FileReader fileReader;
    vector<RelativeVector*> catalogedVec = fileReader.readFile(path);
    KnnAlgorithm kElement(catalogedVec, vector1, kNeighbors, disCalc);
    cout << kElement.classificationUserVec() << endl;

    return 0;
}
