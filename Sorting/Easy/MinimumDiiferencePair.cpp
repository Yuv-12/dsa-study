/*
Given an array arr[]. find the minimum difference between any pair in the given array.
*/

/*
Algorithm: Time complexity = O(n log n)
1) Sort array in ascending order. This step takes O(n Log n) time.
2) Initialize difference as infinite. This step takes O(1) time.
3) Compare all adjacent pairs in sorted array and keep track of minimum difference. This step takes O(n) time.
    Below is implementation of above idea.
*/
#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int min_diff = INT_MAX;
    for (int i = 1; i < arr.size(); i++)
        min_diff = min(min_diff, arr[i] - arr[i - 1]);

    return min_diff;
}