/*Question: Suppose you have a sorted array of infinite numbers, how would you search
an element in the array?
Since the array is sorted the first thought clicks is binary search, but the problem is 
we don't know size of the array.
if the array is of infinite size then to find the key element we have to find the proper
bound to apply the binary search.
=> let low be pointing the first element and high pointing the 2nd element of the array
now compare key with high index
-> if it is greater than high index element then copy the high index in low index and double the high index
-> if it is smaller then apply the binary search in high and low index found.*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int l, int r,int x)
{
    if(l<=r)
    {
        int mid = l + (r - l)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid] > x)
            return binarySearch(arr,l,mid - 1,x);
        else
            return binarySearch(arr,mid+1,r,x);
    }
    return -1;
}

int findPos(int arr[],int key)
{
    int l = 0;
    int h = 1;
    int val = arr[0];
    while(val < key)
    {
        l = h;
        h = 2 * h;
        val = arr[h];
    }
    return binarySearch(arr,l,h,key);
}