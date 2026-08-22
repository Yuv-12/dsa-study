//  You need to complete this function

class Solution {
  public:
    // Function to find the nth fibonacci number using bottom-up approach.
    long long findNthFibonacci(int number) {
        // Your Code Here
        vector<long long> dp(number+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i<=number;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[number];
    }
};