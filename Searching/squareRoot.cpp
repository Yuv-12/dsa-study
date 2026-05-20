/*Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any n*/
#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    if (n == 0 || n == 1)
        return n;

    int low = 1;
    int high = n;
    int ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long sqr = 1LL * mid * mid;
        if (sqr == n)
        {
            return mid;
        }
        else if (sqr < n)
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}