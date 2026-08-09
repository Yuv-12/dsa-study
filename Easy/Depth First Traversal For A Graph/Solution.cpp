class Solution {
  public:
  void DFS(vector<vector<int>> &adj,int src,vector<bool>&visited,vector<int>&res)
  {
      visited[src] = true;
      res.push_back(src);
      for(int u : adj[src])
      {
          if(visited[u] == false)
            DFS(adj,u,visited,res);
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> res;
        int V = adj.size();
        vector<bool> visited(V,false);
        int src = 0;
        DFS(adj,src,visited,res);
        return res;
    }
};