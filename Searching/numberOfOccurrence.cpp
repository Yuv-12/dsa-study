//Given a sorted array arr[] and a target number you need to find the number of occurrences of target in arr[]
#include <bits/stdc++.h>
using namespace std;
int first_occ(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1; // shift the index left
        }
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int last_occ(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1; // shift the index right
        }
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int count_freq(vector<int> &arr, int target)
{
    int first = first_occ(arr, target);
    if (first == -1)
        return 0;
    int last = last_occ(arr, target);
    return last - first + 1;
}