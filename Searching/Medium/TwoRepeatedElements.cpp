/*
You are given an integer array arr of size n+2. All elements of the array are in the range from 1 to n.
Also, all elements occur once except two numbers which occur twice.
Find the two repeating numbers.
Note: Return the numbers in their order of appearing twice.
So, if x and y are repeating numbers, and x's second appearance comes before the
second appearance of y, then the order should be (x, y).*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoRepeated(vector<int> &arr)
{
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        int target_indx = abs(arr[i]) - 1;
        if (arr[target_indx] < 0)
        {
            result.push_back(abs(arr[i]));
        }
        else
        {
            arr[target_indx] *= -1;
        }
    }
    return result;
}