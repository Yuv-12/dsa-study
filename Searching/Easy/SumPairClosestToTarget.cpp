/* Given an array arr[] and a number target,
find a pair of elements (a, b) in arr[], where a ≤ b whose sum is closest to
target.
Note: Return the pair in sorted order and if there are multiple such pairs
return the pair with maximum absolute difference. If no such pair exists return
an empty array.*/
#include <bits/stdc++.h>
using namespace std;
vector<int> sumClosest(vector<int> &arr, int target)
{
    // code here
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n < 2)
        return {};
    int low = 0;
    int high = n - 1;
    int min_diff = INT_MAX;
    int ans1 = 0;
    int ans2 = 0;
    while (low < high)
    {
        int sum = arr[low] + arr[high];
        if (abs(sum - target) < min_diff)
        {
            min_diff = abs(sum - target);
            ans1 = arr[low];
            ans2 = arr[high];
        }
        else if (abs(sum - target) == min_diff)
        {
            if ((arr[high] - arr[low]) > (ans2 - ans1))
            {
                ans1 = arr[low];
                ans2 = arr[high];
            }
        }
        if (sum < target)
            low++;
        else
            high--;
    }
    return {ans1, ans2};
}
