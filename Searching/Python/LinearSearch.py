#Python program to implement Linear Search

#Accepting the number of elements
size = int(input("Enter the number of elements: "))

#Accepting the elements
print("Enter",size,"elements: ", end="")
lt = list(map(int, input().strip().split()))[:size]

#Initializing flag with 0
f = 0

#Accepting the element to be searched
x = int(input("Enter the element to be searched: "))

#Performing Linear Search
for i in range(0,size):
    if(x==lt[i]):
        #Element found
        f = 1
        print(x,"found at position",i+1)
        break

if(f==0):
    #Element not found
    print(x,"not found")