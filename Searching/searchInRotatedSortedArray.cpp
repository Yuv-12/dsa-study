/*Given an array arr[] of distinct elements, which was initially sorted in ascending order
but then rotated at some unknown pivot, the task is to find the index of a target key.
If the key is not present in the array, return -1*/

// solution
/*
1. Find the Pivot: Use binary search. If arr[mid] > arr[high], do low = mid + 1. 
                    Otherwise, do high = mid.

2. Pick the Half: Check if the target falls within the range of the right half (arr[pivot] to arr[n-1]).
                    Set your new low and high accordingly.

3. Final Search: Run a standard binary search on that chosen half to find the exact index of the target.
*/

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&arr,int key)
{
    int low = 0;
    int high = arr.size() - 1;
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    int pivot = low;
    low = 0;
    high = arr.size() -1;
    if(key >= arr[pivot] && key <= arr[high])
        low = pivot;
    else
        high = pivot -1;
    
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid]== key)
            return mid;
        else if(arr[mid]<key)
            low = mid + 1;
        else
            high = mid -1;
    }
    return -1;
}