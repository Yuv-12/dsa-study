/*
Given two sorted arrays arr1[] and arr2[] of size n and m and a number x,
find the pair whose sum is closest to x and the pair has an element from each array.
In the case of multiple closest pairs return any one of them.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
{
    int i = 0;
    int j = arr2.size() - 1;

    int min_diff = INT_MAX;
    int ans1 = 0;
    int ans2 = 0;
    while (i < arr1.size() && j >= 0)
    {
        int sum = arr1[i] + arr2[j];
        if (abs(sum - x) < min_diff)
        {
            min_diff = abs(sum - x);
            ans1 = arr1[i];
            ans2 = arr2[j];
        }
        if (sum == x)
            return {ans1, ans2};
        else if (sum < x)
            i++;
        else
            j--;
    }
    return {ans1, ans2};
}