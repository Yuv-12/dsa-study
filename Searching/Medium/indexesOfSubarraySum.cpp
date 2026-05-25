/*
Given an array arr[] containing only non-negative integers,
your task is to find a continuous subarray (a contiguous sequence of elements)
whose sum equals a specified value target. You need to return the 1-based indices
of the leftmost and rightmost elements of this subarray.
You need to find the first subarray whose sum is equal to the target.

Note: If no such array is possible then, return [-1].*/

#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int current_sum = 0;
    for (int high = 0; high < n; high++)
    {
        current_sum += arr[high];
        while (current_sum > target && low <= high)
        {
            current_sum -= arr[low];
            low++;
        }
        if (current_sum == target && low <= high)
            return {low + 1, high + 1};
    }
    return {-1};
}