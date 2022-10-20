#include<stdio.h>
#include<conio.h>
int main()
{
    int array[10];
    int i, j, n, position, swap, search;
    int first, mid, last;
    printf("Enter the value of number: ");
    scanf("%d", &n);
    printf("Enter value:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    //selection sorting
    for(i = 0; i < (n - 1); i++)
    {
        position=i;
        for(j = i + 1; j < n; j++)
        {
            if(array[position] > array[j])
                position=j;
        }
        if(position != i)
        {
            swap=array[i];
            array[i]=array[position];
            array[position]=swap;
        }
    }
    printf("Sorted value: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nEnter the element to be searched: ");
    scanf("%d", &search);
    //Binary searching
    printf("\n searching....\n");
    sleep(1);
    first = 0;
    last = n-1;

    while(first<=last)
    {
        mid=(first+last)/2;
        if(array[mid]==search)
        {
            printf("We found %d in location %d\n", search, mid+1);
            break;
        }
        else if(array[mid]<search)
        {
            first=mid+1;
        }
        else{
            last = mid-1;

        }
    }
    if(first>last)
            printf("Not found!!! %d is not present.\n", search);

    getch();
    return 0;
}

