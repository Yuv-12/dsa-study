class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i = 0;i<k;i++)
            q.push(arr[i]);
        
        int i;
        for(i= k;i<arr.size();i++)
        {
            q.push(arr[i]);
            arr[i-k] = q.top();
            q.pop();
        }
        while(!q.empty())
        {
            arr[i-k] = q.top();
            q.pop();
            i++;
        }
    }
};