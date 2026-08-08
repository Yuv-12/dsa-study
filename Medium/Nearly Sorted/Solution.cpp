class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> q;
        for(int x: arr)
            q.push(x);
        
        int i = 0;
        while(!q.empty())
        {
            arr[i] = q.top();
            q.pop();
            i++;
        }
    }
};