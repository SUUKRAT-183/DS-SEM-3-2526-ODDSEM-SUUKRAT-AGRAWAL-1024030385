
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool isMaxHeap)
{
    int extreme = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMaxHeap)
    {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    }
    else
    {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i)
    {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, isMaxHeap);
    }
}
void heapSort(int arr[], int n, bool increasing)
{
    bool isMaxHeap = increasing;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }

}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl; 
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n, true);
    cout << "Sorted in Increasing order: ";
    printArray(arr, n);

    heapSort(arr, n, false);
    cout << "Sorted in Decreasing order: ";
    printArray(arr, n);

    return 0;
}