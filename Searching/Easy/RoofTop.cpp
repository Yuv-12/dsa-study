/*
You are given and array arr[] representing the heights of n consecutive buildings.
You can move from the roof of a building to the roof of the next adjacent building.
You need to find the maximum number of consecutive steps you can put forward such
that every step is to a higher building than the previous one. */
#include<bits/stdc++.h>
using namespace std;
int maxStep(vector<int> &arr)
{

    int n = arr.size();
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            count++;
            max_count = max(max_count, count);
        }
        else if (arr[i] >= arr[i + 1])
            count = 0;
    }
    return max_count;
}