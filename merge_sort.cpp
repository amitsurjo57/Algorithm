#include <iostream>
using namespace std;

void Merge(int ar[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int B[high+1];
    while(i<=mid && j<=high)
    {
        if(ar[i]<ar[j])
        {
            B[k++]=ar[i++];
        }
        else
        B[k++]=ar[j++];
    }
    while(i<=mid)
    {
        B[k++]=ar[i++];
    }
    while(j<=high)
    {
        B[k++]=ar[j++];
    }
    for(i=low;i<=high;i++)
    {
        ar[i]=B[i];
    }
    
}
void IterativeMergeSort(int ar[], int n)
{
    int p;
    for (p=2; p<=n; p=p*2)
    {
        for (int i=0; i+p-1<n; i=i+p)
        {
            int low = i;
            int high = i+p-1;
            int mid = (low+high)/2;
            Merge(ar, low, mid, high);
        }
    }
    if (p/2 < n)
    {
        Merge(ar, 0, p/2-1, n-1);
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

    
    IterativeMergeSort(A,n);
    cout<<"Sorted array: ";
    for (int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}
