/*
Given the arrival and departure times of all trains that reach a railway station, the task is to find 
the minimum number of platforms required for the railway station so that no train waits. 
We are given two arrays that represent the arrival and departure times of trains that stop.
*/

/*
Algorithm:
1. Sort both the arrival and departure arrays.
2. Put two pointers i and j at the beginning of both arrays.
3. Create two variables:
    curr_count -> stores currently occupied platforms.
    max_count  -> stores maximum platforms needed till now.
4. Initially:
    curr_count = 1
    max_count = 1
    i = 1
    j = 0
5. Traverse both arrays using:
    while(i < arrival.size() && j < departure.size())
6. If arrival[i] <= departure[j]:
    -> A new train arrives before the previous one departs.
    -> One more platform is needed.
    -> curr_count++
    -> i++
7. Else:
    -> A train departs before the next train arrives.
    -> One platform becomes free.
    -> curr_count--
    -> j++
8. Update:
    max_count = max(max_count, curr_count)
9. After traversal, max_count will be the minimum number of platforms required.
*/

#include<bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>&arr,vector<int>&dep)
{
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

    int i = 0;
    int j = 0;
    int curr_count = 0;
    int max_count = 0;

    while(i<arr.size() && j<dep.size())
    {
        if(arr[i]<=dep[j])
        {
            curr_count++;
            max_count = max(curr_count,max_count);
            i++;
        }
        else
        {
            curr_count--;
            j++;
        }
    }
    return max_count;
}