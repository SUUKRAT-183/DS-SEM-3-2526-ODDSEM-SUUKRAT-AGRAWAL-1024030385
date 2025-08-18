#include <iostream>
using namespace std;

int main() {
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    int i, j, temp;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted list in ascending order:\n";
    for (i = 0; i < 7; i++)
        cout << arr[i] << endl;

    return 0;
}
