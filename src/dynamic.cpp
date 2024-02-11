#include <iostream>
#include <vector>
#include <string>

// Function to find the longest common substring
std::string longestCommonSubstring(const std::string& S, const std::string& T) {
    int n = S.size();
    // Creating a 2D vector to act as our table, initialized with zeros
    std::vector<std::vector<int> > L(n+1, std::vector<int>(n+1, 0));
    int longest = 0; // Variable to keep track of the length of the longest common substring found
    std::string result; // String to store the longest common substring

    // Build the table using dynamic programming
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            // Initial condition, first row and column remain as zero
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (S[i-1] == T[j-1]) {
                // If characters match, set this cell to 1 plus the top-left diagonal cell's value
                L[i][j] = L[i-1][j-1] + 1;
                // If this is the longest substring found so far, update the longest variable
                // and store the current substring
                if (L[i][j] > longest) {
                    longest = L[i][j];
                    result = S.substr(i-longest, longest);
                }
            } else {
                // If characters do not match, set the cell's value to 0
                L[i][j] = 0;
            }
        }
    }

    // Printing the table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << L[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Return the longest common substring
    return result;
}

int main() {
    std::string S1, S2;

    // Input: Get two strings from the user
    std::cout << "Enter the first string: ";
    std::cin >> S1;
    std::cout << "Enter the second string: ";
    std::cin >> S2;

    // Check if strings are of equal length before proceeding
    if (S1.size() != S2.size()) {
        std::cout << "Strings must be of the same length. Please try again.\n";
        return 1; // Exit the program if strings are not of equal length
    }

    // Processing: Find the longest common substring
    std::string lcs = longestCommonSubstring(S1, S2);

    // Output: Display the longest common substring
    std::cout << "Longest Common Substring: \"" << lcs << "\"\n";

    return 0;
}
