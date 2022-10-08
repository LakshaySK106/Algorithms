def mergeSort(a):
	width = 1
	n = len(a)										
	while (width < n):
		l=0;
		while (l < n):
			r = min(l+(width*2-1), n-1)		
			m = min(l+width-1,n-1)		
			merge(a, l, m, r)
			l += width*2
		width *= 2
	return a

def merge(a, l, m, r):
	n1 = m - l + 1
	n2 = r - m
	L = [0] * n1
	R = [0] * n2
	for i in range(0, n1):
		L[i] = a[l + i]
	for i in range(0, n2):
		R[i] = a[m + i + 1]

	i, j, k = 0, 0, l
	while i < n1 and j < n2:
		if L[i] <= R[j]:
			a[k] = L[i]
			i += 1
		else:
			a[k] = R[j]
			j += 1
		k += 1

	while i < n1:
		a[k] = L[i]
		i += 1
		k += 1

	while j < n2:
		a[k] = R[j]
		j += 1
		k += 1


a = [-74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,-39]
print("Given array is ")
print(a)
mergeSort(a)

print("Sorted array is ")
print(a)