class Solution {
  public:
  void addEdge(vector<vector<int>>&adj,int u,int v)
  {
      adj[u].push_back(v);
  }
  void DFS(vector<vector<int>>&adj,int src,vector<bool> &visited,stack<int>&st)
  {
      visited[src] = true;
      for(int v : adj[src])
      {
          if(!visited[v])
            DFS(adj,v,visited,st);
      }
      st.push(src);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            addEdge(adj,edges[i][0],edges[i][1]);
        }
        vector<bool> visited(V,false);
        stack<int> st;
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
                DFS(adj,i,visited,st);
        }
        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};