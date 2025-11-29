#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n / 2; i++)
    {
        int min = i;
        int max = i;
        int end = n - 1 - i;

        for (int j = i; j <= end; j++)
        {
            if (a[j] < a[min])
                min = j;
            if (a[j] > a[max])
                max = j;
        }

        // Swap minimum to beginning
        if (min != i)
            swap(a[min], a[i]);

        // If max was at position i and moved due to previous swap, update max index
        if (max == i)
            max = min;

        // Swap maximum to end
        if (max != end)
            swap(a[max], a[end]);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
