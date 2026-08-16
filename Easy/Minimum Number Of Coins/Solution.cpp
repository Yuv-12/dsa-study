class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int> coin = {10,5,2,1};
        int res = 0;
        for(int i = 0;i<coin.size();i++)
        {
            if(coin[i]<=n)
            {
                int c = (n/coin[i]);
                res += c;
                n  = n - c*coin[i];
            }
            if(n==0)
                break;
        }
        return res;
    }
};