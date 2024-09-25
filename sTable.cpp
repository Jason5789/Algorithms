#include <iostream>
#include <climits>

using namespace std;

void matrix_chain_order(int p[], int n) {
    int s[n + 1][n + 1];

    // Initialize
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = 0;
        }
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            s[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = s[i][k] + s[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < s[i][j]) {
                    s[i][j] = q;
                }
            }
        }
    }

    // Print the s table
    cout << "s Table:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int p[] = {2, 3, 5, 4, 2}; // Dimensions of matrices
    int n = sizeof(p) / sizeof(p[0]) - 1;
    matrix_chain_order(p, n);
    return 0;
}