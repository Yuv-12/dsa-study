class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,100000000);
        dist[src] = 0;
        for(int count = 0;count<V-1;count++)
        {
            for(auto edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u]!=100000000 && dist[v] > dist[u]+w)
                    dist[v] = dist[u] + w;
            }
        }
        
        for(auto edge : edges)
        {
            int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u]!=100000000 && dist[v] > dist[u]+w)
                    return {-1};
        }
        return dist;
    }
};
