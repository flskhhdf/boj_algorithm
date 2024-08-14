#include <iostream>
using namespace std;

const int MAX = 6;  // MAX 값을 충분히 큰 값으로 설정 (배열의 크기)

double OBST_DP(double P[], double Q[], int n, double PQ[MAX][MAX])
{
    double EV[MAX][MAX];
    int RT[MAX][MAX], d, i, j, r;

    // Initialize base cases
    for (i = 1; i <= n + 1; i++) {
        EV[i][i - 1] = PQ[i][i - 1] = Q[i - 1];
    }

    // Loop over diagonal values
    for (d = 0; d <= n - 1; d++) {
        for (i = 1; i <= n - d; i++) {
            j = i + d;
            // Update PQ[i][j]
            PQ[i][j] = PQ[i][j - 1] + P[j - 1] + Q[j];
            // Initialize EV[i][j]
            EV[i][j] = 2147483647;  // INT_MAX
            // Loop over possible roots
            for (r = i; r <= j; r++) {
                if (EV[i][r - 1] + EV[r + 1][j] + PQ[i][j] < EV[i][j]) {
                    EV[i][j] = EV[i][r - 1] + EV[r + 1][j] + PQ[i][j];
                    RT[i][j] = r;
                }
            }
        }
    }

    return EV[1][n];
}

int main() {
    double P[] = {0.25, 0.05, 0.15, 0.15, 0.1};
    double Q[] = {0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
    int n = sizeof(P) / sizeof(P[0]) - 1;  // Subtract 1 to get the correct size

    double PQ[MAX][MAX];
    double result = OBST_DP(P, Q, n, PQ);

    cout << "Expected Value for the optimal BST: " << result << endl;

    // Print PQ matrix
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            cout << "PQ[" << i << "][" << j << "]: " << PQ[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
