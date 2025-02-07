#include <iostream>
using namespace std;
void Merge(int ar[],int low,int mid,int high){
    mid=(low+high)/2;
    int i=low;
    int j=mid+1;
    int k=low;
    int B[high+1];
    while(i<=mid && j<=high){
        if(ar[i]<ar[j]){
            B[k++]=ar[i++];
        }
        else
        B[k++]=ar[j++];
    }
    while(i<=mid){
        B[k++]=ar[i++];
    }
    while(j<=high){
        B[k++]=ar[j++];
    }
    for(i=low;i<=high;i++){
        ar[i]=B[i];
    }   
}
void MergeSort(int ar[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(ar,low,mid);
        MergeSort(ar,mid+1,high);
        Merge(ar,low,mid,high);
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
    MergeSort(A,0,n-1);
    cout<<"Sorted array: ";
    for (int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
