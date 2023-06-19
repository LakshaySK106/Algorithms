#include<iostream>
#include<conio.h>
using namespace std;

void insertion_sort(int a[],int n)
{
    int i,j,tmp;

    for(i=1;i<n;i++)
    {
        tmp=a[i];
        j=i-1;
        while(a[j]>tmp && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=tmp;
    }

    cout << "Sorted values are:"<<endl;
    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[100],i,n;

    cout << "Enter size of array: ";
    cin>>n;

    cout << "Enter values:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    insertion_sort(a,n);

    return 0;
}
