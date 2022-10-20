
## Exponential Search in Python

def binarySearch( arr, l, r, x):
	if r >= l:
		mid = l + ( r-l ) // 2
		
		# If the element is present at the middle itself
		if arr[mid] == x:
			return mid
		
		# If the element is smaller than mid, then it can only be present in the left subarray
		if arr[mid] > x:
			return binarySearch(arr, l, mid - 1, x)
		
		# Else he element can only be present in the right
		return binarySearch(arr, mid + 1, r, x)
		
	# We reach here if the element is not present
	return -1


def exponentialSearch(arr, n, x):
	# IF x is present at first location itself
	if arr[0] == x:
		return 0
		
	# Find range for binary search j by repeated doubling
	i = 1
	while i < n and arr[i] <= x:
		i = i * 2
	
	return binarySearch( arr, i // 2, min(i, n-1), x)
	


arr = [2, 3, 4, 10, 21, 40]
n = len(arr)
x = 21
result = exponentialSearch(arr, n, x)
if result == -1:
	print ("Element not found in the array")
else:
	print ("Element is present at index %d" %(result))

