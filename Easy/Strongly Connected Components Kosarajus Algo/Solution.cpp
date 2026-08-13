class Solution {
  public:
  void addEdge(vector<vector<int>> &adj,int u,int v)
  {
      adj[u].push_back(v);
  }
  void DFS1(vector<vector<int>>&adj,int src,vector<bool>&visited1,stack<int>&st)
  {
      visited1[src] = true;
      for(int v : adj[src])
      {
          if(!visited1[v])
            DFS1(adj,v,visited1,st);
      }
      st.push(src);
  }
  void graphTranspose(vector<vector<int>>&adj,vector<vector<int>>&trans)
  {
      for(int i = 0;i<adj.size();i++)
      {
          for(int j = 0;j<adj[i].size();j++)
          {
              trans[adj[i][j]].push_back(i);
          }
      }
  }
  void DFS2(vector<vector<int>>&trans,int src,vector<bool>&visited2)
  {
      visited2[src] = true;
      for(int v : trans[src])
      {
          if(!visited2[v])
            DFS2(trans,v,visited2);
      }
  }
  
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            addEdge(adj,u,v);
        }
        stack<int>st;
        vector<bool> visited1(V,false);
        for(int i = 0;i<V;i++)
        {
            if(!visited1[i])
                DFS1(adj,i,visited1,st);
        }
        vector<vector<int>> trans(V);
        graphTranspose(adj,trans);
        
        vector<bool>visited2(V,false);
        int count = 0;
        while(!st.empty())
        {
            int i = st.top();
            st.pop();
            if(!visited2[i])
            {
                DFS2(trans,i,visited2);
                count++;
            }
        }
        return count;
    }
};