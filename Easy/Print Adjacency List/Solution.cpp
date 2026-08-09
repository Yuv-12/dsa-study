class Solution {
  public:
  void addEdge(vector<vector<int>> &adj,int u,int v)
  {
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        int E = edges.size();
        for(int i = 0;i<E;i++)
        {
            addEdge(adj,edges[i].first,edges[i].second);
        }
        return adj;
    }
};