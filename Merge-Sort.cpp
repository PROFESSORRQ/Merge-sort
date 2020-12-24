#include <bits/stdc++.h>
#include <algorithm>
#include <hashtable.h>
#include <math.h>
#include <vector>
#include <string>
using namespace std;
#define Nmax INT_MAX;
int mergearray(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];  //temp arrays
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=b[j];
            j++;
            k++;
        }
        
    }
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
     while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r, int n)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid, n);
        mergesort(arr, mid + 1, r, n);
        mergearray(arr, l, mid, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0;
    int r = n - 1;
    mergersort(arr, l, r, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}