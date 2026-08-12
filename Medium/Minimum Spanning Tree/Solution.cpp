class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int res = 0;
        vector<vector<int>> graph(V,vector<int>(V,0));
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u][v] = edges[i][2];
            graph[v][u] = edges[i][2];
        }
        
        vector<int> key(V,INT_MAX);
        key[0] = 0;
        vector<bool> mstSet(V,false);
        for(int count = 0;count<V;count++)
        {
            int u = -1;
            for(int i =0;i<V;i++)
            {
                if(!mstSet[i] && (u==-1 || key[i] < key[u]))
                    u = i;
            }
            mstSet[u]= true;
            res = res+key[u];
            for(int v = 0;v<V;v++)
            {
                if(graph[u][v]!= 0 && !mstSet[v])
                {
                    key[v] = min(key[v],graph[u][v]);
                }
            }
        }
        return res;
    }
};