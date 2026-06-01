/*
Given an array arr[] of positive integers.The task is to complete the
insertsort() function which is used to implement Insertion Sort.*/

// solution
/*Insertion sort is an in-place sorting algorithm
-> It work similar way of sorting a deck of playing card.
-> The idea is to start from the second element of the array till the last element
    and for every element insert at its correct position in the subarray before it.
*/
/*
Algorithm:
1. If the current element is the first element then it is already sorted.
2. pick the next element
3. compare the current with the all element in the sorted subarray before it.
4. Shift all the element int the subarray before the current element which are
    greater than the current element by 1 place and insert the current element at new empty space.
5. Repeat the step 2 - 3 until the entire array is sorted
*/
#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

// Time Complexity: O(n*n)