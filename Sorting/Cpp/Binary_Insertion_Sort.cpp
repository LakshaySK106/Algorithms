// Binary search sort

#include <iostream>
using namespace std;

// iterative implementation
int binarySearch(int a[], int item, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

// Function to sort the array

void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        // find location where selected should be inseretd

        loc = binarySearch(a, selected, 0, j);

        // Move all elements after location to create space

        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : \n";
    cin >> n;
    int a[n];
    cout << "Enter the array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    insertionSort(a, n);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << " " << a[i];

    return 0;
}
