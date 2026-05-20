/*Given a sorted array arr consisting of 0s and 1s. The task is to find the index (0-based indexing) of the first 1 in the given array.
NOTE: If one is not present then, return -1.*/
#include <bits/stdc++.h>
using namespace std;
int firstIndex(vector<int> &arr) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid]==1)
            {
                ans = mid;
                high = mid -1;
            }
            else if( arr[mid] < 1)
            {
                low = mid + 1;
            }
        }
        return ans;
    }