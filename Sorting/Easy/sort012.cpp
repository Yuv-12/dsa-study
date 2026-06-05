/*
Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array.
The functions should put all 0s first, then all 1s and all 2s in last.
*/

/*
This is also known as Dutch National Flag Algorithm.
The logic is to maintain three regions:

1. Elements from 0 to low-1 are all 0s.
2. Elements from low to mid-1 are all 1s.
3. Elements from high+1 to n-1 are all 2s.

The region from mid to high contains unprocessed elements.

If arr[mid] is 0:
- Swap it with arr[low].
- Increment both low and mid since the element is now placed in its correct region.

If arr[mid] is 1:
- It already belongs to the middle region.
- Simply increment mid.

If arr[mid] is 2:
- Swap it with arr[high].
- Decrement high.
- Do not increment mid because the element that comes from the
    high position is still unprocessed and must be checked again.

Continue until mid crosses high.
*/

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/
#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;

    while (high >= mid)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
            mid++;
    }
}