#include <bits/stdc++.h>
using namespace std;
 
// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
 
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
 
        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
 
        // Condition of target found
        if (arr[pos] == x)
            return pos;
 
        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
 
        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}
 
int main()
{
 
    int n,x;
    cout<<"Enter array size:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array:";
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Enter the element to be searched : ";
    cin>>x;
    int index = interpolationSearch(arr, 0, n - 1, x);
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";
 
    return 0;
}
