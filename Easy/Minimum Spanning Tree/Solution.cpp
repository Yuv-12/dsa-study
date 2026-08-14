class Solution {
  public:
  int find(vector<int>&parent,int i )
  {
      if(parent[i] == i)
        return i;
        return parent[i] = find(parent,parent[i]);
  }
  
  void Union(vector<int>&parent,vector<int>&rank,int i,int j)
  {
      int irep = find(parent,i);
      int jrep = find(parent,j);
      if(irep==jrep)
        return;
        else
        {
            if(rank[irep] < rank[jrep])
                parent[irep] = jrep;
            else if(rank[irep]>rank[jrep])
                parent[jrep] = irep;
            else
            {
                parent[jrep] = irep;
                rank[irep]++;
            }
        }
  }
  
  static bool myCMP(vector<int>&a,vector<int>&b)
  {
      return a[2] < b[2];
  }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> parent(V);
        vector<int> rank(V,0);
        sort(edges.begin(),edges.end(),myCMP);
        for(int i = 0;i<V;i++)
        {
            parent[i] = i;
        }
        int minCost = 0;
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int urep = find(parent,u);
            int vrep = find(parent,v);
            if(urep!=vrep)
            {
                minCost += w;
                Union(parent,rank,u,v);
            }
        }
        return minCost;
    }
};