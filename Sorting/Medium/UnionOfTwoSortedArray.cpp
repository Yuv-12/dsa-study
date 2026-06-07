/*
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements
in the union of the two arrays in sorted order.
Union of two arrays can be defined as the set containing distinct common elements that are present in either of the array
*/
/*
Algorithm: Time Complexity = O(n + m), Space Complexity = O(n + m)

1. Initialize two pointers:
    i = 0 for array a[]
    j = 0 for array b[]

2. Create an empty result vector res.

3. Traverse both arrays while i < n and j < m:

a) If a[i] < b[j]:
        - Add a[i] to result if it is not already the last inserted element.
        - Increment i.

b) If a[i] > b[j]:
        - Add b[j] to result if it is not already the last inserted element.
        - Increment j.

c) If a[i] == b[j]:
        - Add the element once if it is not already present at the end of result.
        - Increment both i and j.

4. After one array is exhausted:
    - Add remaining elements of a[] while avoiding duplicates.
    - Add remaining elements of b[] while avoiding duplicates.

5. Return the result vector containing all distinct elements
in sorted order.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    vector<int> res;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            if (res.empty() || res.back() != a[i])
                res.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            if (res.empty() || res.back() != b[j])
                res.push_back(b[j]);
            j++;
        }
        else
        {
            if (res.empty() || res.back() != a[i])
                res.push_back(a[i]);
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (res.empty() || res.back() != a[i])
            res.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        if (res.empty() || res.back() != b[j])
            res.push_back(b[j]);
        j++;
    }
    return res;
}