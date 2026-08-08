class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<int,vector<int>,greater<int>> q;
        vector<int> res;
        
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                q.push(mat[i][j]);
            }
        }
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};