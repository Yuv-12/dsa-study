class Solution {
  public:
  void addEdge(vector<vector<pair<int,int>>>&adj,vector<int>&indegree,int u,int v,int w)
  {
      adj[u].push_back({v,w});
      indegree[v]++;
  }
  void topSort(vector<vector<pair<int,int>>>&adj,vector<int>&indegree
            ,vector<int>&topo)
            {
                queue<int> q;
                for(int i = 0;i<indegree.size();i++)
                {
                    if(indegree[i] == 0)
                        q.push(i);
                }
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    topo.push_back(u);
                    for(auto edge : adj[u])
                    {
                        int v = edge.first;
                        indegree[v]--;
                        if(indegree[v]==0)
                            q.push(v);
                    }
                }
            }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V);
        for(int i = 0;i<edges.size();i++)
            addEdge(adj,indegree,edges[i][0],edges[i][1],edges[i][2]);
            
        vector<int> topo;
        topSort(adj,indegree,topo);
        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        for(int u : topo)
        {
            if(dist[u] == INT_MAX)
                continue;
            for(auto edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;
                if(dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
        for(int i = 0;i<V;i++)
        {
            if(dist[i]==INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};
