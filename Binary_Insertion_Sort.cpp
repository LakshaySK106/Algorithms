#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int item, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
  
    return low;
}
  
void insertionSort(int arr[], int n)
{
    int i, loc, j, k, selected;
  
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];
  
        loc = binarySearch(arr, selected, 0, j);
  
        
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}
  

int main()
{
    int arr[] = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
    int n = sizeof(arr) / sizeof(arr[0]), i;
  
    insertionSort(arr, n);
   cout<<"Sorted array by Binary Insertion Sort: \n";
    for (i = 0; i < n; i++)
        cout <<" "<< arr[i];
  
    return 0;
}