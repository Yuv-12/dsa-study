/*
You are given an integer array arr[].
Your task is to find the smallest positive number missing from the array.*/

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        while (arr[i] != i + 1)
        {
            if (arr[i] <= 0 || arr[i] > n || arr[arr[i] - 1] == arr[i])
                break;
            else
                swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}