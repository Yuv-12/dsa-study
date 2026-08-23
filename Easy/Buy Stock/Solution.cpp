class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int minPrice = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i = 1;i<n;i++)
        {
            minPrice = min(minPrice,prices[i]);
            maxProfit = max(maxProfit,prices[i] - minPrice);
        }
        return maxProfit;
    }
};
