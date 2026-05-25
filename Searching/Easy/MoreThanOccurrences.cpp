/*Given an array arr and an element k.
The task is to find the count of elements in the array that appear more than n/k times and n is length of arr.*/
#include <bits/stdc++.h>
using namespace std;
// using hashing in O(n) time and O(n) space complexity
int countOccurence(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> freq;
    for (int x : arr)
        freq[x]++;

    int count = 0;
    for (auto x : freq)
    {
        if (x.second > (n / k))
            count++;
    }
    return count;
}

//Extended Boyer-Moore Voting Algorithm (Optimal Memory)

