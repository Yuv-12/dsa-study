/*
Given an array of distinct elements which was initially sorted.
This array may be rotated at some unknown point. The task is to find the minimum element in the given sorted and rotated array.
*/

#include <bits/stdc++.h>
using namespace std;

int minNumber(int arr[], int low, int high)
{

    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= arr[high])
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}