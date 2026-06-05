/*
Given an array arr[] consisting of only 0's and 1's. Modify the array in-place to
segregate 0s onto the left side and 1s onto the right side of the array.
*/
#include <bits/stdc++.h>
using namespace std;

void segregate0and1(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low < high)
    {
        if (arr[low] == 0)
            low++;
        else
        {
            swap(arr[low], arr[high]);
            high--;
        }
    }
}