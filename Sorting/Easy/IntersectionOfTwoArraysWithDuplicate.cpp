/*
Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said
to be elements that are common in both the arrays. The intersection should not have duplicate elements and the result may
contain elements in any order.

Note: The driver code will sort the resulting array in increasing order before printing.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &a, vector<int> &b)
{
    unordered_set<int> st(a.begin(), a.end());
    vector<int> res;
    for (int x : b)
    {
        if (st.find(x) != st.end())
        {
            res.push_back(x);
            st.erase(x);
        }
    }
    return res;
}