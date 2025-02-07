#include <iostream>
using namespace std;

// void swap(int &x,int &y)
// {
//     int temp=x;
//     x=y;
//     y=temp;
// }

void BubbleSort(int ar[],int n)
{
   
    for (int i=0;i<n-1;i++)
    {
        int flag=0;
        for (int j=0;j<n-1-i;j++)
        {
            if (ar[j]>ar[j+1])
            {
                swap(ar[j],ar[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
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

    BubbleSort(A,n);

    cout<<"Sorted array: ";
    for (int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}
