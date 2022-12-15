#include "Validations.h"


/**
 * The function check if the input has negative sign that the user enters is in a valid format.
 *
 * @param string1 the user input string.
 * @param i the for loop counter.
 * @return return false if isn't valid and true if valid
 * (we get the loop counter by reference because if valid we want to continue).
 */
bool Validations::validNegative(string string1, unsigned long &i) {
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
 * Checking if the number is in scientific notation.
 * If so, convert it to the numeric value of it represented as a string. If not, return it as it came.
 * @param str The string to check.
 * @return the string changed or not.
 */
string Validations::isScientificNotation(const string &str) {
    // Saving the string in a temporary value.
    string temp = str;
    // Creating a control pointer.
    char *end;
    // trying to convert the string.
    double result = strtod(str.c_str(), &end);
    // If the string is not convertable, return the original string.
    if (end == str.c_str() || *end != '\0') {
        return temp;
    }
    // If the string is convertable, return the converted version.
    string strResult = to_string(result);
    return strResult;
}


/**
 * The function check if the input has '.' sign that the user enters is in a valid format(floating point format).
 *
 * @param string1 the user input string.
 * @param i the for loop counter.
 * @return return false if isn't valid and true if valid
 * (we get the loop counter by reference because if valid we want to continue).
 */
bool Validations::validFloatingNumber(string string1, unsigned long &i) {
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
bool Validations::isNumber(string s) {
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


string Validations::isScientificNotationValid(const string str) {
    // Create a new stream to go over the line.
    istringstream line(str);
    // Initiate a string to store the data from toNum.
    string lastStr, result;
    // Create a validation instance.
    Validations valid;
    // Read each data segment seperated by comma.
    while (getline(line, lastStr, ' ')) {
        // Checking if the number is in scientific notation.
        result = result + valid.isScientificNotation(lastStr) + " ";
    }
    result.pop_back();
    return result;
}
