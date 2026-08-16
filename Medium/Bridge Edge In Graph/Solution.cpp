class Solution {
  public:
  bool DFS(int u,int parent,vector<vector<int>>&adj,vector<int>&disc,
            vector<int>&low,vector<bool>&visited,int c, int d,int &timer)
            {
                visited[u] = true;
                disc[u] = low[u] = timer++;
                for(auto v : adj[u])
                {
                    if(v==parent)
                        continue;
                    if(!visited[v])
                    {
                        if(DFS(v,u,adj,disc,low,visited,c,d,timer))
                        {
                            return true;
                        }
                        low[u] = min(low[u],low[v]);
                        if(low[v]>disc[u])
                        {
                            if((u==c && v==d) || (v==c && u == d)) 
                                return true;
                        }
                        
                    }
                    else
                    {
                        low[u] = min(low[u],disc[v]);
                    }
                }
                return false;
            }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        vector<bool>visited(V,false);
        int timer = -1;
        
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                if(DFS(i,-1,adj,disc,low,visited,c,d,timer))
                    return true;
            }
        }
        return false;
    }  
};