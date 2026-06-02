/*
Given two sorted arrays a[] and b[] of size n and m respectively,
merge them in sorted order without using any extra space.

After merging:
- a[] should contain the first n smallest elements
- b[] should contain the remaining m largest elements
*/

/*
Logic:
Compare the largest elements of array a[] with the smallest
elements of array b[].

If an element in a[] is greater than an element in b[],
swap them.

Continue this process until all possible misplaced elements
are swapped.

Finally, sort both arrays individually to restore sorted order.
*/

#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m)
    {
        if (a[i] > b[j])
            swap(a[i], b[j]);

        i--;
        j++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}
/*
Complexity:
    Swapping phase → O(min(n,m))
    Sorting:
        sort(a) → O(n log n)
        sort(b) → O(m log m)

    Total:O(n log n + m log m)
    
    Space:O(1)
*/