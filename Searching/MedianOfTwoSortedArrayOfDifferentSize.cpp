/*Given two sorted arrays a[] and b[],
find and return the median of the combined array after merging them into a single sorted array.*/

// solution
/*
Optimal Approach : Binary Search Partition

1. Always perform binary search on the smaller array.
   This reduces time complexity and prevents partition
   index from going out of bounds.

2. Let:

   n = size of first array
   m = size of second array
   tot = total number of elements

3. Apply binary search on first array.

4. Partition both arrays such that left half contains:

      (tot + 1) / 2

   elements in total.

5. Let:

   mid1 = partition index in first array
   mid2 = remaining required elements in second array

6. Elements around partitions:

   l1 = last element on left side of first array
   r1 = first element on right side of first array

   l2 = last element on left side of second array
   r2 = first element on right side of second array

7. Handle edge cases using:

   INT_MIN when no element exists on left side
   INT_MAX when no element exists on right side

8. Correct partition condition:

      l1 <= r2
   and
      l2 <= r1

   This means all left half elements are smaller
   than all right half elements.

9. Median calculation:

   -> If total elements are odd:

      median = max(l1,l2)

   -> If total elements are even:

      median =
      ( max(l1,l2) + min(r1,r2) ) / 2.0

10. If l1 > r2:

    move towards left in first array.

11. Else:

    move towards right in first array.

Time Complexity  : O(log(min(n,m)))
Space Complexity : O(1)
*/
#include <bits/stdc++.h>
using namespace std;

double medianOf2(vector<int> &a, vector<int> &b)
{
    // code here
    int n = a.size();
    int m = b.size();
    int tot = m + n;
    if (n > m)
        return medianOf2(b, a);
    int low = 0;
    int high = n;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = ((tot + 1) / 2) - mid1;
        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int r1 = (mid1 == n) ? INT_MAX : a[mid1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r2 = (mid2 == m) ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1)
        {
            if (tot % 2 != 0)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0.0;
}