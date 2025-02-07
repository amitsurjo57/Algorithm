#include <iostream>
using namespace std;

void InsertionSort(int ar[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=ar[i];
        while(j>-1 && ar[j]>x)
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=x;
    }
}

int main()
{
    int n;
    cin>>n;

    int A[n];
    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    InsertionSort(A,n);

    cout<<"Sorted array: ";
    for (int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}
