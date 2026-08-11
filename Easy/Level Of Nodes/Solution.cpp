class Solution {
  public:
  void addEdge(vector<vector<int>> &adj,int u,int v)
  {
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
    int nodeLevel(int V, vector<vector<int>>& edges, int x) {
        // code here
        vector<vector<int>> adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            addEdge(adj,edges[i][0],edges[i][1]);
        }
        vector<bool>visited(V,false);
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0] = true;
        int level = 0;
        while(!q.empty())
        {
            int u = q.front().first;
            int level  = q.front().second;
            q.pop();
            if(x==u)
                return level;
            for(int v : adj[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push({v,level+1});
                    
                }
            }
        }
        return -1;
    }
};