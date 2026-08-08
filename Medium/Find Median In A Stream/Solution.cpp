class Solution {
  public:
    vector<double>getMedian(vector<int> &arr) {
        // code here
        vector<double> res;
        priority_queue<int> left;
        priority_queue<int,vector<int>,greater<int>> right;
        for(int x : arr)
        {
            if(left.empty() || x <= left.top())
                left.push(x);
            else
                right.push(x);
                
            if(left.size() > right.size()+1)
            {
                right.push(left.top());
                left.pop();
                
            }
            else if(left.size() < right.size())
            {
                left.push(right.top());
                right.pop();
            }
            if(left.size() == right.size())
            {
                double median = (left.top() + right.top() )/ 2.0;
                res.push_back(median);
            }
            else
                res.push_back(left.top());
        }
        return res;
    }
};
