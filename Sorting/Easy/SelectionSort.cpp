/*Given an array arr, use selection sort to sort arr[] in increasing order.*/

// Solution
/*
Selection sort algorithm sort an array by repeatedly finding minimum element
(considering ascending order) from unsorted part and putting it at begining.
The algorithm maintains two subarrays in a given array.
1. The subarray which is already sorted.
2. Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element
(considering ascending order) from the unsorted subarray is picked and moved
to the sorted subarray.
*/
#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr)
{

    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (arr[i] != arr[min_idx])
            swap(arr[i], arr[min_idx]);
    }
}

//Time complexity: O(n*n)
