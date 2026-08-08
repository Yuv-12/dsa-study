class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> q;
        for(int x : arr)
        {
            q.push(x);
        }
        int total = 0;
        while(q.size()>=2)
        {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            total += first + second;
            q.push(first + second);
        }
        return total;
    }
};