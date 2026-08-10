class Solution {
  public:
  void addEdge(vector<vector<int>>&adj,int u,int v)
  {
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  
  bool DFS(vector<vector<int>> &adj,int src,vector<bool> &visited,int parent)
  {
      visited[src] = true;
      for(int u : adj[src])
      {
          if(visited[u] == false)
          {
              if(DFS(adj,u,visited,src)==true)
                return true;
          }
          else if(u!=parent)
                    return true;
         
      } 
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i = 0;i<edges.size();i++)
            addEdge(adj,edges[i][0],edges[i][1]);
        
        vector<bool> visited(V,false);
        for(int i = 0;i<V;i++)
        {
            if(visited[i] == false)
            {
                if(DFS(adj,i,visited,-1)==true)
                    return true;
            }
        }
        return false;
        
        
        
        
        
        
    }
};