Binary Insertion Sort

// code

#include <iostream>
using namespace std;

int binarySearch(int a[], int item, int low, int high)
{
	while (low <= high) {
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

void insertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i) {
		j = i - 1;
		selected = a[i];

		loc = binarySearch(a, selected, 0, j);

		while (j >= loc) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

int main()
{
	int a[]
		= { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	int n = sizeof(a) / sizeof(a[0]), i;

	insertionSort(a, n);

	cout <<"Sorted array: \n";
	for (i = 0; i < n; i++)
		cout <<" "<< a[i];

	return 0;
  
}

