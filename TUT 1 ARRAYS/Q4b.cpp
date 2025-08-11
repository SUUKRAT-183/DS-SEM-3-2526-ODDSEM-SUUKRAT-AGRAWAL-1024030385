#include <iostream>
using namespace std;

int main() {
    int i, j, m1, m2, n1, n2, sum = 0, k = 0, l = 0, p = 0, r = 0, x = 0;

    cout << "Enter number of rows of matrix 1: ";
    cin >> n1;
    cout << "Enter number of columns of matrix 1: ";
    cin >> n2;
    int M1[n1][n2];

    cout << "Enter number of rows of matrix 2: ";
    cin >> m1;
    cout << "Enter number of columns of matrix 2: ";
    cin >> m2;
    int M2[m1][m2];

    cout << "Enter elements of array 1:\n";
    for (i = 0; i < n1; i++)
        for (j = 0; j < n2; j++)
            cin >> M1[i][j];

    cout << "Enter elements of array 2:\n";
    for (i = 0; i < m1; i++)
        for (j = 0; j < m2; j++)
            cin >> M2[i][j];

    int M3[n1][m2];

    for (i = 0; i < (n1 * m2); i++) {
        for (j = 0; j < m1; j++) {
            sum += (M1[x][k] * M2[k][l]);
            k++;
        }
        M3[p][r] = sum;
        r++;
        if (r % m2 == 0)
            x++;
        if (r == m2) {
            r = 0;
            p++;
        }
        l++;
        if (l == m2)
            l = 0;
        k = 0;
        sum = 0;
    }

    cout << "Multiplied array is:\n";
    for (i = 0; i < n1; i++) {
        for (j = 0; j < m2; j++) {
            cout << M3[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
