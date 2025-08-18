#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n; 
}

int main() {

    int n,i,arr[100];
    cout<<"Enter value of n<100 \n";
    cin>>n;
    cout << "Enter " << n-1 << " sorted numbers from 1 to " << n << ":\n";
    for (i = 0; i < n-1; i++) {
        cin >> arr[i];
    }
    int missing = findMissingNumber(arr, n);
    cout << "Missing number: " << missing << endl;
    
    return 0;
}
