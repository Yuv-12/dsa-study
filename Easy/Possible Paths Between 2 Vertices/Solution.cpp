class Solution {
  public:
    int dfs(int u,int dest,vector<vector<int>>&adj,vector<int> &memo)
    {
        if(u==dest)
            return 1;
        
        if(memo[u]!=-1)
            return memo[u];
        
        int total_path = 0;
        for(int v : adj[u])
        {
            total_path += dfs(v,dest,adj,memo);
        }
        memo[u] = total_path;
        return total_path;
    }
    int countPaths(int V, vector<vector<int>>& edges, int src, int dest) {
        // code here
        vector<vector<int>> adj(V);
        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> memo(V,-1);
        return dfs(src,dest,adj,memo);
    }
};