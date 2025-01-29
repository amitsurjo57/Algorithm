#include <bits/stdc++.h>
using namespace std;

int inversionCount = 0;

void conquer(int arr[], int si, int mid, int ei)
{
    int n1 = mid - si + 1;
    int n2 = ei - mid;

    int *left = new int[n1];
    int *right = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[si + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = si;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            inversionCount += (n1 - i);
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

void divide(int arr[], int si, int ei)
{

    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;
    divide(arr, si, mid);
    divide(arr, mid + 1, ei);
    conquer(arr, si, mid, ei);
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
        cout << endl;
    }

    divide(arr, 0, size - 1);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of inversions: " << inversionCount << endl;

    delete[] arr;
}