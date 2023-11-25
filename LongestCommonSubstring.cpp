#include <iostream>
#include <vector>

using namespace std;

// Function to discover the longest common substring between two provided strings
string findLongestCommonSubstring(const string &firstInput, const string &secondInput, size_t &substringLength) {
    // Determine the length of the input strings
    size_t length = firstInput.length();

    // Construct a 2D vector to store the lengths of common substrings
    vector<vector<size_t>> dpTable(length + 1, vector<size_t>(length + 1, 0));

    // Variables to hold the length and ending position of the longest common substring
    size_t maxSubstringLength = 0;
    size_t endPosition = 0;

    // Populate the dynamic programming table
    for (size_t i = 1; i <= length; ++i) {
        for (size_t j = 1; j <= length; ++j) {
            // Check if characters at the current positions match
            if (firstInput[i - 1] == secondInput[j - 1]) {
                // If a match is found, extend the length of the common substring
                dpTable[i][j] = dpTable[i - 1][j - 1] + 1;

                // Update the length and ending position if a longer substring is found
                if (dpTable[i][j] > maxSubstringLength) {
                    maxSubstringLength = dpTable[i][j];
                    endPosition = i - 1;
                }
            }
        }
    }

    // Retrieve the longest common substring
    string longestSubstring = firstInput.substr(endPosition - maxSubstringLength + 1, maxSubstringLength);

    // Set the output variable for the length of the substring
    substringLength = maxSubstringLength;

    // Display the 2D grid
    cout << "2D Grid:" << endl;
    for (size_t i = 0; i <= length; ++i) {
        for (size_t j = 0; j <= length; ++j) {
            cout << dpTable[i][j] << " ";
        }
        cout << endl;
    }

    return longestSubstring;
}

int main() {
    // Accept two strings from the user
    string userString1, userString2;
    cout << "Enter the first string: ";
    cin >> userString1;
    cout << "Enter the second string: ";
    cin >> userString2;

    // Variable to store the length of the longest common substring
    size_t lengthOfSubstring;

    // Determine the longest common substring
    string result = findLongestCommonSubstring(userString1, userString2, lengthOfSubstring);

    // Display the result along with the length of the substring
    cout << "Longest Common Substring: " << result << " (Length: " << lengthOfSubstring << ")" << endl;

    return 0;
}
