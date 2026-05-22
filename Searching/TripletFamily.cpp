/*Given an array arr[] of integers,
check whether there exist three elements such that the sum of two elements is equal
to the third element. */

// solution

/*
1. Sort the array.
2. Loop i starting from the end of the array (n - 1) down to 2 (since you need at least two numbers before it to form a pair).
3. Set your target: target = arr[i].
4. Set pointers: low = 0 and high = i - 1.
5. Run your while (low < high) loop:
6. If arr[low] + arr[high] == target, you found it! Return true.
7. If the sum is less than the target, you need a bigger number, so low++.
8. If the sum is greater than the target, you need a smaller number, so high--.
9. If the loops finish with no match, return false.
*/

#include <bits/stdc++.h>
using namespace std;

bool findTriplet(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = n - 1; i >= 2; i--)
    {
        int low = 0;
        int high = i - 1;
        while (low < high)
        {
            int sum = arr[low] + arr[high];
            int target = arr[i];
            if (target == sum)
                return true;
            else if (target > sum)
                low++;
            else
                high--;
        }
    }
    return false;
}