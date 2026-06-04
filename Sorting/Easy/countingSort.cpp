/*
Counting Sort is a non-comparison sorting algorithm used when the input values
are integers within a known and limited range.

Algorithm:
1. Find the maximum element in the array.
2. Create a count array of size (max_element - min_element + 1) and initialize all values to 0.
3. Traverse the input array and count the occurrences of each element.
4. Compute the prefix sum (cumulative count) of the count array.
5. Create an output array of size n.
6. Traverse the input array from right to left (to make the algorithm stable):

    for (i = n - 1; i >= 0; i--) {
        output[count[input[i]] - 1] = input[i];
        count[input[i]]--;
    }

7. Copy the output array back to the original array (if required).

Time Complexity: O(n + k)
Space Complexity: O(n + k)

where:
n = number of elements in the input array
k = range of input values (maximum value)
*/

#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr)
{
    int maxEl = *max_element(arr.begin(), arr.end());
    int minEl = *min_element(arr.begin(), arr.end());

    int range = maxEl - minEl + 1;

    vector<int> count_arr(range, 0), output(arr.size());

    for (int i = 0; i < arr.size(); i++)
        count_arr[arr[i] - minEl]++;
    for (int i = 1; i < count_arr.size(); i++)
        count_arr[i] = count_arr[i] + count_arr[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count_arr[arr[i] - minEl] - 1] = arr[i];
        count_arr[arr[i] - minEl]--;
    }
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

/*
Time Complexity: O(n + k)
Space Complexity: O(n + k)

where:
n = number of elements
k = maxElement - minElement + 1
*/