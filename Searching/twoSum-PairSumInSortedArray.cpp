/*Given a 1-based indexed integer array arr[] that is sorted in non-decreasing order,
along with an integer target. find two elements in the array such that their sum is
equal to target. If such a pair exists, return the indices of the two elements in
increasing order. If no such pair exists, return [-1, -1].*/

/*we use two pointer to solve this problem which solve the problem in O(N)*/

#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &arr, int target)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
            return {i + 1, j + 1};
        else if (arr[i] + arr[j] > target)
            j--;
        else
            i++;
    }
    return {-1, -1};
}