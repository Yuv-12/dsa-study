class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();

        if (n == 0 || k == 0)
            return 0;

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int t = 1; t <= k; t++) {
            int best = -prices[0];

            for (int i = 1; i < n; i++) {
                // Don't sell today
                curr[i] = curr[i - 1];

                // Sell today
                curr[i] = max(curr[i],
                              prices[i] + best);

                // Best place to buy
                best = max(best,
                           prev[i] - prices[i]);
            }

            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }

        return prev[n - 1];
    }
};