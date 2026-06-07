/*
Given two sorted arrays arr1[] and arr2[]. Your task is to return the intersection of both arrays.
Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not count duplicate elements.
Note: If there is no intersection then return an empty array.
*/

/*
Algorithm: Time Complexity = O(n + m), Space Complexity = O(k)

1. Initialize two pointers:
    i = 0 for arr1[]
    j = 0 for arr2[]

2. Create an empty result vector res.

3. Traverse both arrays while i < n and j < m:

a) If arr1[i] == arr2[j]:
        - This element belongs to the intersection.
        - Insert it only if it is different from the last inserted element
        (to avoid duplicates).
        - Increment both i and j.

b) If arr1[i] < arr2[j]:
        - arr1[i] cannot appear later in arr2.
        - Increment i.

c) If arr1[i] > arr2[j]:
        - arr2[j] cannot appear later in arr1.
        - Increment j.

4. When either array is exhausted, stop.
No more common elements are possible.

5. Return the result vector.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();
    vector<int> res;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            if (res.empty() || arr1[i] != res.back())
                res.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    return res;
}