class Solution {
  public:
  void addEdge(vector<vector<int>> &adj,int u,int v)
  {
      adj[u].push_back(v);
  }
  
  bool DFS(vector<vector<int>>&adj,int src,vector<bool>&visited,vector<bool>& reccSt)
  {
      visited[src] = true;
      reccSt[src] = true;
      for(int u : adj[src])
      {
          if(visited[u]==false && DFS(adj,u,visited,reccSt))
            return true;
        else if(reccSt[u])
            return true;
      }
      reccSt[src] = false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            addEdge(adj,edges[i][0],edges[i][1]);
        }
        
        vector<bool> visited(V,false);
        vector<bool> reccSt(V,false);
        for(int i = 0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(DFS(adj,i,visited,reccSt))
                    return true;
            }
        }
        return false;
    }
};