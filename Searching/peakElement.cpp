/*You are given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist).

If there are multiple peak elements, Return index of any one of them. The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".

Note: Consider the element before the first element and the element after the last element to be negative infinity.*/

#include <bits/stdc++.h>
using namespace std;

int peakElement(int *arr, int n)
{
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1;
    int high = n - 2;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid]< arr[mid-1])
            high = mid -1;
        else
            low = mid +1;
    }
    return -1;
}
