#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main() {
    const int max = 100; // max allowed
    int arr[max];
    int size;

    cout << "Enter size of array (max 100): ";
    cin >> size;
    if (size > max) {
        cout << "Size too large! Using maximum size 100.\n";
        size = max;
    }

    cout << "Enter " << size << " elements for array:\n";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    reverseArray(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
