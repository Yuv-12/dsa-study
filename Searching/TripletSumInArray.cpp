/*Given an array arr[] and an integer target,
determine if there exists a triplet in the array whose sum equals the given target.
Return true if such a triplet exists, otherwise, return false.*/

// solution
/*
1. Sort the array.
2. Loop i from 0 to n - 2.
3. Set pointers: low = i + 1 and high = n - 1.
4. Run a while (low < high) loop.
5. If arr[i] + arr[low] + arr[high] == target, return true.
6. If the sum is less than the target, do low++.
7. If the sum is greater than the target, do high--.
8. If all loops finish with no match, return false.
*/

#include <bits/stdc++.h>
using namespace std;

bool hasTripletSum(vector<int> &arr, int target)
{

    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int sum = arr[i] + arr[low] + arr[high];
            if (sum == target)
            {
                return true;
            }
            else if (sum < target)
                low++;
            else
                high--;
        }
    }
    return false;
}