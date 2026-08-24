class Solution {
  public:
    int trailingZeroes(int n) {
        // code here
        int total = 0;
        for(int i = 5;i <= n;i=i*5)
        {
            total += n/i;
        }
        return total;
    }
};