/*Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order.
Given an array arr[], with starting index low and ending index high, complete the functions partition() and quickSort().
Use the last element as the pivot, so that all elements less than or equal to the pivot come before it, and elements greater than the pivot follow it.*/

// Solution
/*
->Quick Sort is a divide-and-conquer algorithm. It picks an element as a pivot and partition the given array around the picked pivot.
    There are many different version of quick sort that pick pivot in different ways
    1. Always pick first element as pivot.
    2. Always pick last element as pivot.
    3. Pick a random element as pivot.
    4. Pick median as pivot.
*/
// Reference: https://youtube.com/shorts/MeBYqiehwyQ?si=NTWaHGy2iMxaMWoo

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
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(arr, low, high);
        quickSort(arr, low, partition_index - 1);
        quickSort(arr, partition_index + 1, high);
    }
}

/*
Time Complexity
Case	Complexity
Best	O(n log n)
Average	O(n log n)
Worst	O(n²)

Worst Case: The worst case occurs when the partition process always picks greatest or smallest element as pivot. If we consider above partition strategy where last element is always picked as pivot, the worst case would occur when the array is already sorted in increasing or decreasing order. Following is recurrence for worst case.
            T(n) = T(0) + T(n-1) + Θ(n)
            which is equivalent to
            T(n) = T(n-1) + Θ(n)
            The solution of above recurrence is Θ(n^2).

Best Case: The best case occurs when the partition process always picks the middle element as pivot.
    Following is recurrence for best case.
    T(n) = 2T(n/2) + Θ(n)
    The solution of above recurrence is Θ(nLogn). It can be solved using case 2 of Master Theorem.

Average Case: To do average case analysis, we need to consider all possible permutation of array and calculate time taken by
            every permutation which doesn't look easy.
            We can get an idea of average case by considering the case when partition puts O(n/9)
            elements in one set and O(9n/10) elements in other set. Following is recurrence for this case.
            T(n) = T(n/9) + T(9n/10) + Θ(n)
            Solution of above recurrence is also O(nLogn)

Although the worst case time complexity of QuickSort is O(n^2) which is more than many other sorting algorithms like Merge Sort
and Heap Sort, QuickSort is faster in practice, because its inner loop can be efficiently implemented on most architectures,
and in most real-world data. QuickSort can be implemented in different ways by changing the choice of pivot,
so that the worst case rarely occurs for a given type of data. However, merge sort is generally considered better when data
is huge and stored in external storage.
*/