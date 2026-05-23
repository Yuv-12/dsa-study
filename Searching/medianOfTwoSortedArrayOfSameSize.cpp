/*Given two sorted arrays a[] and b[] of equal size,
find and return the median of the combined array after merging them into a single sorted array.*/

// solution
/*
Optimal Approach : Binary Search Partition

1. Always apply binary search on the smaller array
   to reduce time complexity and avoid out of bounds.

2. We partition both arrays into left half and right half
   such that:

   left half contains ((n + m + 1) / 2) elements.

3. Let:

   mid1 = partition index in first array
   mid2 = remaining elements needed in left half
          from second array.

4. Elements around partition:

   l1 = last element on left side of first array
   r1 = first element on right side of first array

   l2 = last element on left side of second array
   r2 = first element on right side of second array

5. If:

      l1 <= r2
   and
      l2 <= r1

   then correct partition is found.

6. Median calculation:

   -> If total number of elements is even:

      median =
      ( max(l1,l2) + min(r1,r2) ) / 2.0

   -> If total number of elements is odd:

      median = max(l1,l2)

7. If l1 > r2:

   move towards left in first array
   because larger elements are taken from first array.

8. Else:

   move towards right in first array
   because smaller elements are taken from first array.

Time Complexity  : O(log(min(n,m)))
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

double medianOf2(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    int low = 0;
    int high = n;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = m - mid1;
        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int r1 = (mid1 == n) ? INT_MAX : a[mid1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r2 = (mid2 == m) ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1)
        {
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0.0;
}