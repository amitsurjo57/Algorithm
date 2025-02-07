#include <iostream>
using namespace std;

void SelectionSort(int ar[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(ar[j]<ar[k])
            {
                k=j;
            }
        }
        swap(ar[i],ar[k]);
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

    SelectionSort(A,n);
            
    cout<<"Sorted array: ";
    for (int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}
