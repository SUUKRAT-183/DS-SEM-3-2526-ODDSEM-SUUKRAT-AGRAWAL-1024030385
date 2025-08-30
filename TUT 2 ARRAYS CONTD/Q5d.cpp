#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter order of square matrix (n x n): ";
    cin >> n;

    int arr[100][100];
    cout << "Enter the tri-diagonal matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "The entered matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int tri[5050]; 
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j ) {
                tri[k++] = arr[i][j];
            }
        }
    }

    cout << "The stored 1D array is:\n";
    for (int i = 0; i < k; i++) {
        cout << tri[i] << " ";
    }
    cout << endl;

    cout << "Space saved: Instead of " << n * n 
         << " elements, we only stored " << k << " elements.\n";

    return 0;
}
