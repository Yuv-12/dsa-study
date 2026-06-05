/*
Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.
*/

// solution
/*
Brute Force: Sort the array in increasing order and then return the k-1th element from the begining of the
            array.

Complexity Analysis:
    Time Complexity: O(n log n) (due to sorting)
    Space Complexity: O(1) (ignoring the space used by the sorting algorithm)
*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    if (k < 1 || k > arr.size())
        return -1;
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

/*
Better Approach (Quick Select):

1. Choose a pivot and partition the array.
2. Let p be the pivot's final index after partitioning.

    - If p == k - 1, the pivot itself is the kth smallest element.
    - If p > k - 1, search in the left subarray.
    - If p < k - 1, search in the right subarray.

3. Unlike Quick Sort, we recurse into only one side of the array,
    which reduces the average time complexity.

Complexity Analysis:
    Average Time Complexity: O(n)
    Worst Case Time Complexity: O(n²)
    Space Complexity: O(1) iterative, O(log n) average recursive stack
*/

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

int quickSelect(vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high);

        if (pi == k - 1)
            return arr[pi];
        else if (pi > k - 1)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1;
}

int KthSmallest(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    return quickSelect(arr, low, high, k);
}

/*
Heap Approach (Max Heap of Size k)

The idea is to maintain a max heap containing the k smallest elements seen so far.

Algorithm:
1. Insert the first k elements into a max heap.
2. Traverse the remaining elements:
    If the current element is smaller than the heap's top (largest among the current k smallest elements), remove the top and insert the current element.
3. After processing all elements, the heap's top will be the kth smallest element.
*/

int kthSmallest(vector<int> &arr, int k)
{
    if (k < 1 || k > arr.size())
        return -1;

    priority_queue<int> maxHeap;

    // Insert first k elements
    for (int i = 0; i < k; i++)
        maxHeap.push(arr[i]);

    // Process remaining elements
    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}