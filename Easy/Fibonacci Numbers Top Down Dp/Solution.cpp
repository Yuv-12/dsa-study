
class Solution {
  public:
    // Function to find the nth fibonacci number using top-down approach.
    long long findNthFibonacci(int number, long long int dp[]) {
        
        // Base cases
        if(number <= 1)
            return number;
        
        // Already calculated
        if(dp[number] != 0)
            return dp[number];
        
        // Calculate and store
        return dp[number] = 
            findNthFibonacci(number - 1, dp) +
            findNthFibonacci(number - 2, dp);
    }
};