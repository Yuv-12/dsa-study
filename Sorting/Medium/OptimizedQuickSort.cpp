/*
QUICKSORT TAIL CALL OPTIMIZATION

Problem:
--------
Normal QuickSort makes two recursive calls:

quickSort(left);
quickSort(right);

Worst Case:
-----------
If pivot always ends up at one end
(e.g., sorted array + last element as pivot),

sizes become: n-1, n-2, n-3, ...

Recursion depth = O(n)
Auxiliary stack space = O(n)
--------------------------------------------------
STEP 1: Tail Call Elimination
-----------------------------

Convert one recursive call into iteration.

Instead of:

quickSort(left);
quickSort(right);

Use:

quickSort(left);
low = pi + 1;   // process right part iteratively

Result:
- Only one recursive call remains.
- Still O(n) stack space in worst case.
--------------------------------------------------
STEP 2: Recurse on Smaller Partition
---------------------------------
After partition:

Left size  = pi - low
Right size = high - pi

Always recurse on the smaller side.

if(left_size < right_size)
{
    quickSort(left);      // smaller side
    low = pi + 1;         // larger side handled iteratively
}
else
{
    quickSort(right);     // smaller side
    high = pi - 1;        // larger side handled iteratively
}
--------------------------------------------------
Why O(log n) Space?
-------------------
Each recursive call works on at most half of the remaining elements.
Sizes become:
n
n/2
n/4
n/8
...

Maximum depth: n/(2^k) = 1
=> k = log2(n)
Therefore:  Recursion depth = O(log n)
            Auxiliary space = O(log n)
--------------------------------------------------

Time Complexity
---------------
Best Case    : O(n log n)
Average Case : O(n log n)
Worst Case   : O(n²)
(The optimization only reduces stack space, not the time complexity.)

Important Interview Point
-------------------------

Normal QuickSort: Worst-case stack space = O(n)
Optimized QuickSort: Worst-case stack space = O(log n)

Technique: "Always recurse on the smaller partition and process the larger partition iteratively."
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    while (low < high)
    {
        int pi = partition(arr, low, high);

        // Recur for smaller partition
        if (pi - low < high - pi)
        {
            quickSort(arr, low, pi - 1);
            low = pi + 1; // Process larger part iteratively
        }
        else
        {
            quickSort(arr, pi + 1, high);
            high = pi - 1; // Process larger part iteratively
        }
    }
}
