/*Given a sorted array arr[] with possibly some duplicates, find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.*/
#include <bits/stdc++.h>
using namespace std;
int first_occ(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1; // left search
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}
int last_occ(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1; // right search
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}
vector<int> find(vector<int> &arr, int x)
{
    return {first_occ(arr, x), last_occ(arr, x)};
}
