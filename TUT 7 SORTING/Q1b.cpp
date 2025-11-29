// insertion sort
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int j, temp, i;
    int a[n];
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 0; i < n; i++)
    {
        temp = a[i];
        j=i;
        while(j>0&&a[j-1]>temp)
        {
           a[j]=a[j-1];
           j--;
        }
        a[j]=temp;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}