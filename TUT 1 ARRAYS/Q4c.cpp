#include <iostream>
using namespace std;

int main() {
    int i, j, n1, n2;
    cout << "Enter number of rows and columns: ";
    cin >> n1 >> n2;

    int M1[n1][n2];
    cout << "Enter elements of array:\n";
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            cin >> M1[i][j];
        }
    }

    int M2[n2][n1];
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            M2[j][i] = M1[i][j];
        }
    }

    cout << "Transpose of entered array is:\n";
    for (i = 0; i < n2; i++) {
        for (j = 0; j < n1; j++) {
            cout << M2[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
