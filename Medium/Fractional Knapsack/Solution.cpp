class Solution {
  public:
  static bool myComp(const vector<double>&a,const vector<double>&b)
  {
      return a[2] > b[2];
  }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<double>> valwtRatio;
        for(int i = 0;i<val.size();i++)
        {
            valwtRatio.push_back({(double)val[i],
                                (double)wt[i],
                                ((double)val[i]/wt[i])});
        }
        sort(valwtRatio.begin(),valwtRatio.end(),myComp);
        double res = 0.0;
        int curr_capacity = capacity;
        for(int i = 0;i<valwtRatio.size();i++)
        {
            double itemVal = valwtRatio[i][0];
            double itemWt = valwtRatio[i][1];
            
            if(itemWt <= curr_capacity)
            {
                curr_capacity -= itemWt;
                res += itemVal;
            }
            else
            {
                res += (itemVal) * ((double)curr_capacity/itemWt);
                return res;
            }
        }
        return res;
    }
};
