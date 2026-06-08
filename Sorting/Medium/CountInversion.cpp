/*
Given an array of integers arr[]. You have to find the Inversion Count of the array.
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].
*/

/*
Algorithm:
1. Divide the array into two halves.
2. Recursively count inversions in the left half.
3. Recursively count inversions in the right half.
4. Merge the two sorted halves while counting cross-inversions:
    If arr[i] <= arr[j], copy arr[i].
    Otherwise, arr[i] > arr[j], so all elements from i to mid form inversions with arr[j].
    Add (mid - i + 1) to the inversion count.
*/

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int l, int mid, int r)
{
    int count = 0;
    vector<int> result(r - l + 1);
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
            result[k++] = arr[i++];
        else
        {
            result[k++] = arr[j++];
            count += mid - i + 1;
        }
    }
    while (i <= mid)
        result[k++] = arr[i++];

    while (j <= r)
        result[k++] = arr[j++];
    for (int i = l; i <= r; i++)
        arr[i] = result[i - l];
    return count;
}

int mergeSort(vector<int> &arr, int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid + 1, r);
        count += merge(arr, l, mid, r);
    }
    return count;
}

int inversionCount(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}
