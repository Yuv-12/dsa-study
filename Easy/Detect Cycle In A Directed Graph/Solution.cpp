class Solution {
  public:
  void addEdge(vector<vector<int>> &adj,int u,int v,vector<int> &indegree)
  {
      adj[u].push_back(v);
      indegree[v]++;
  }
  
 
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(int i = 0;i<edges.size();i++)
        {
            addEdge(adj,edges[i][0],edges[i][1],indegree);
        }
        queue<int> q;
        for(int i = 0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> res;
        int count = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int v : adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
            count++;
            
        }
        return (count!=V);
    }
};