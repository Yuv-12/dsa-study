/*
Given an array of intervals arr[][], where arr[i] = [starti, endi].
The task is to merge all overlapping intervals.
*/

/*
Algorithm:

1. Sort all intervals based on their starting points.

2. Assume the first interval is already merged.
    Let res = 0 represent the index of the last merged interval.

3. Traverse the remaining intervals from i = 1 to n - 1.

4. For each interval:
    a) If the current interval overlaps with the interval at res
        (i.e., arr[res][1] >= arr[i][0]),
        merge them by:
        - Taking the minimum starting point.
        - Taking the maximum ending point.

    b) Otherwise, no overlap exists:
        - Increment res.
        - Copy the current interval to arr[res].

5. After traversal, intervals from index 0 to res
    contain all merged intervals.

6. Remove all extra intervals after index res.

7. Return the modified array.

Time Complexity: O(n log n)
    - Sorting takes O(n log n)
    - Merging takes O(n)

Space Complexity: O(1)
    - In-place merging (excluding output space)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());
    if (arr.empty())
        return {};
    int res = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[res][1] >= arr[i][0])
        {
            arr[res][0] = min(arr[res][0], arr[i][0]);
            arr[res][1] = max(arr[res][1], arr[i][1]);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }
    arr.erase(arr.begin() + res + 1, arr.end());
    return arr;
}