#include<iostream.h>
using namespace std;
int selection(int[],int);
int minimum(int *a,int n,int &min,int i)
{
    int j;
    for(j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
        {
            min=j;
        }
    }
}

int main()
{
    int a[100],n,i;
    cout<<"ENTER NUMBER OF ITEMS: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"ENTER ITEM "<<i+1<<":";
        cin>>a[i];
    }

    selection(a,n);

    cout<<"SORTED DATA"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}    

int selection(int *A,int N)
{
    int i,min;

    for(i=0;i<N-1;i++)
    {
        min=i;
        minimum(A,N,min,i); 
        swap(A[i],A[min]);
    }
}