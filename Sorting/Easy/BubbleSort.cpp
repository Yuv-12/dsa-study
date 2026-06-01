/*Given an array, arr[]. Sort the array using bubble sort algorithm.*/

// Solution
/*
->Bubble sort is an in-place sorting algorithm.
->It work on principle: In one iteration if we swap all elements of an array such
    that after swap the first element is less than the second element then at end
    of the iteration, the first element will be the minimum element.
*/
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for(int i = 0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j = 0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            return;
    }
}