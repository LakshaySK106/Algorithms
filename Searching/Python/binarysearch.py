
## Binary Search Algo in python

def binarySearch(arr, left, right, x):
	# Check base case
	if right >= l:
		mid = left + (right - l) // 2
		# If element is present at the middle itself
		if arr[mid] == x:
			return mid
		# If element is smaller than mid, then it can only be present in left subarray
		elif arr[mid] > x:
			return binarySearch(arr, left, mid-1, x)
		# Else the element can only be present in right subarray
		else:
			return binarySearch(arr, mid + 1, right, x)
	else:
		# Element is not present in the array
		return -1


arr = [100, 3000, 204, 295, 185, 395]
x = 204

# calling binary seach function to seach x in arr
result = binarySearch(arr, 0, len(arr)-1, x)

if result != -1:
	print("Element is present at index % d" % result)
else:
	print("Element is not present in array")
