/*
You are given two arrays a[] and b[], return the Union of both the arrays in any order.

The Union of two arrays is a collection of all distinct elements present in either of the arrays.
If an element appears more than once in one or both arrays, it should be included only once in the result.

Note: Elements of a[] and b[] are not necessarily distinct.
Note that, You can return the Union in any order but the driver code will print the result in sorted order only.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    unordered_set<int> st;
    for (int x : a)
        st.insert(x);
    for (int x : b)
        st.insert(x);

    vector<int> res(st.begin(), st.end());
    return res;
}