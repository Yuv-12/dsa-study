class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
         vector<int> res;
         int V = adj.size();
         vector<bool> visited(V,false);
         queue<int> q;
         visited[0] = true;
         q.push(0);
         while(!q.empty())
         {
             int u = q.front();
             q.pop();
             res.push_back(u);
             for(int v : adj[u])
             {
                 if(visited[v] == false)
                 {
                     visited[v]  = true;
                     q.push(v);
                 }
             }
         }
         return res;
    }
};