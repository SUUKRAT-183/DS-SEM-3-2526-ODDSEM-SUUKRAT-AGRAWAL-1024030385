#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int first = 0, last = n - 2;  
    int middle;

    while (first <= last) {
        middle = (first + last) / 2;

        if (arr[middle] == middle + 1) {
            first = middle + 1;
        } 
        else {
            last = middle - 1;
        }
    }
    return first + 1;
}

int main() {
    int n, i, arr[100];

    cout << "Enter value of n < 100: ";
    cin >> n;

    cout << "Enter " << n - 1 << " sorted numbers from 1 to " << n << ":\n";
    for (i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int missing = findMissingNumber(arr, n);
    cout << "Missing number: " << missing << endl;

    return 0;
}
