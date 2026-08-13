class Solution {
  public:
  typedef pair<int,int> ipair;
  void addEdge(vector<vector<ipair>>&adj,int u ,int v,int w)
  {
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
  }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector< ipair>> adj(V);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            addEdge(adj,u,v,w);
        }
        
        priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
        pq.push({0,src});
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for(auto edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};