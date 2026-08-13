class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>
                        > pq;
        
        vector<bool> visited(V,false);
        pq.push({0,0});
        int res = 0;
        while(!pq.empty())
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(visited[u])
                continue;
            visited[u] = true;
            res += wt;
            for(auto edge : adj[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if(!visited[v])
                    pq.push({weight,v});
            }
        }
        return res;
    }
};