class Solution {
  public:
  int solve (string &s1, string &s2,int m,int n,vector<vector<int>>&dp)
  {
      if(m==0 || n==0)
        return 0;
    
    if(s1[m-1] == s2[n-1])
        return dp[m][n] = 1+solve(s1,s2,m-1,n-1,dp);
    if(dp[m][n]!=-1)
        return dp[m][n];
    return dp[m][n] = max(solve(s1,s2,m,n-1,dp),solve(s1,s2,m-1,n,dp));
  }
    int lcs(string &s1, string &s2) {
        // code here
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,m,n,dp);
    }
};
