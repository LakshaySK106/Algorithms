package main

import "fmt"

func main() {
	x := []int{1, 4, 2, 3, 7, 9, 5}
	mergeSort(x, 0, len(x)-1)
	fmt.Println(x)

}

func mergeSort(array []int, low int, high int) {
	var mid = low + (high-low)/2
	mergeSort(array, low, mid)
	mergeSort(array, mid+1, high)
	merge(array, low, mid, high)

}

func merge(array []int, low int, mid int, high int) {
	size1 := mid - low + 1
	size2 := high - mid
	array1 := []int{}
	array2 := []int{}

	for iter1 := 0; iter1 < size1; iter1++ {
		array1[iter1] = array[low+iter1]
	}
	for iter2 := 0; iter2 < size2; iter2++ {
		array2[iter2] = array[mid+1+iter2]
	}

	iter1 := 0
	iter2 := 0
	mergeIter := low
	for iter1 < size1 && iter2 < size2 {
		if array1[iter1] <= array2[iter2] {
			array[mergeIter] = array1[iter1]
			mergeIter++
			iter1++
		} else {
			array[mergeIter] = array2[iter2]
			mergeIter++
			iter2++
		}
	}
	for iter1 < size1 {
		array[mergeIter] = array1[iter1]
		mergeIter++
		iter1++
	}

	for iter2 < size2 {
		array[mergeIter] = array2[iter2]
		mergeIter++
		iter2++
	}

}
