#include <iostream>

using namespace std;

bool matchString(char* s1, char* s2, int length) {
    for (int i = 0; i < length; i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // declare and initialize the 3D char matrix
    char matrix[3][3][3] = {
        {{'m', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}},
        {{'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r'}},
        {{'s', 't', 'u'}, {'v', 'w', 'x'}, {'y', 'z', 'a'}}
    };

    // declare and initialize the string to be searched for
    char searchString[] = "skc";

    // loop through all possible starting positions in the matrix for the string search
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                // check for diagonal strings starting at this position

                // direction 1: horizontal and vertical in the same plane
                if (k <= 2 && j <= 2 && i <= 2) {
                    char diagonalString[4] = "";
                    int n = 0;
                    while (i+n <= 2 && j+n <= 2 && k+n <= 2 && n < 3) {
                        diagonalString[n] = matrix[i+n][j+n][k+n];
                        n++;
                    }
                    if (matchString(diagonalString, searchString, n) && n >= 2 && n <= 3) {
                        // found a match
                        cout << "horizontal and vertical in the same plane Match found at position [" << i << "][" << j << "][" << k << "]" << endl;
                    }
                }

                // direction 2: in the same row but different planes
                if (j <= 2 && i <= 2) {
                    char diagonalString[4] = "";
                    int n = 0;
                    while (i+n <= 2 && k+n <= 2 && n < 3) {
                        diagonalString[n] = matrix[i+n][j][k+n];
                        n++;
                    }
                    if (matchString(diagonalString, searchString, n) && n >= 2 && n <= 3) {
                        // found a match
                        cout << "in the same row but different planes Match found at position [" << i << "][" << j << "][" << k << "]" << endl;
                    }
                }

                // direction 3: in the same column but different planes
                if (k <= 2 && j <= 2) {
                    char diagonalString[4] = "";
                    int n = 0;
                    while (i+n <= 2 && j+n <= 2 && n < 3) {
                        diagonalString[n] = matrix[i+n][j+n][k];
                        n++;
                    }
                    if (matchString(diagonalString, searchString, n) && n >= 2 && n <= 3) {
                        // found a match
                        cout << "in the same column but different planes Match found at position [" << i << "][" << j << "][" << k << "]" << endl;
                    }
                }
            }
        }
    }

return 0;
}  