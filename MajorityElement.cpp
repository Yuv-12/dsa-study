/*Given an array arr[].
Find the majority element in the array. If no majority element exists, return -1.

Note: A majority element in an array is an element that appears strictly more
than arr.size()/2 times in the array*/

// solution
/*
Pass 1 (Find the candidate): Loop through the array keeping track of a candidate and a count.
        Increase the count if the current number matches the candidate,
        decrease it if it's different. If the count hits 0, pick the current number as the new candidate and reset the count to 1.

Pass 2 (Verify the candidate): Loop through the array one more time to count the actual total appearances of your candidate.

Check: If the total appearances are greater than half the array size, return the candidate. Otherwise, return -1.*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(int arr[], int n)
{
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count++;
            candidate = arr[i];
        }
        else if (candidate == arr[i])
            count++;
        else
            count--;
    }
    int cand_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
            cand_count++;
    }
    if (cand_count > (n / 2))
        return candidate;
    else
        return -1;
}
