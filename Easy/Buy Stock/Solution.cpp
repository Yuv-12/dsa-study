class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1;i<n;i++)
        {
            minPrice = min(minPrice,prices[i]);
            maxProfit = max(maxProfit,prices[i] - minPrice);
        }
        return maxProfit;
    }
};
