/*Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.*/

/*Merge Sort is a Divide and Conquer algorithm. It divides the input array in two halves,
calls itself for the two halves and then merges the two sorted halves. The merge() function is
used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and
arr[m+1..r] are sorted and merges the two sorted sub-arrays into one in a sorted manner.*/
#include <bits/stdc++.h>
using namespace std;
// Merge Sort With Extra Space
/*
Time Complexity
Recurrence: T(n)=2T(2n)+O(n)
Using Master Theorem:
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

void merge(vector<int> &arr, int l, int mid, int r)
{
    int i = l;
    int j =  mid + 1;
    int k = 0;
    vector<int> result(r - l + 1);
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
            result[k++] = arr[i++];
        else
            result[k++] = arr[j++];
    }
    while(i<=mid)
        result[k++] = arr[i++];
    while(j<=r)
        result[k++] = arr[j++];
    for (int i = l; i <= r; i++)
        arr[i] = result[i - l];
}

void mergeSort(vector<int>&arr,int l,int r)
{
    if(l<r)
    {
        int mid = l +(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
