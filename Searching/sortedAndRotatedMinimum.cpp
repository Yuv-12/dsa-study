/*A sorted array of distinct elements arr[] is rotated at some unknown point,
the task is to find the minimum element in it. */

/*The solution of this is the pivot element*/
/*Find the Pivot: Use binary search. If arr[mid] > arr[high], do low = mid + 1.
                    Otherwise, do high = mid.*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    int ans = arr[low];
    return ans;
}