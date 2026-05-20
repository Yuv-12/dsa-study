/*You are given a binary array that is sorted in non-increasing order, meaning all the 1's appear before the 0's.
Find the total number of 1's present in the array.*/

/*using binary search*/
#include <bits/stdc++.h>
using namespace std;
int countOnes(vector<int> &arr)
{
    int low = 0;
        int high = arr.size() - 1;
        int last = -1;
        while(low <=high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] == 1)
            {
                last = mid;
                low = mid + 1;
            }
            else
            {
                high = mid -1;
            }
        }
        return last + 1;
}

/*Using c++ STL lower and upper bound*/
#include <bits/stdc++.h>
using namespace std;
int countOnes(vector<int> &arr)
{
    return lower_bound(arr.begin(), arr.end(), 0, greater<int>()) - arr.begin();
}