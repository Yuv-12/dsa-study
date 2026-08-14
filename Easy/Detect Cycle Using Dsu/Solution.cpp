class Solution {
  public:
  int find(vector<int>&parent,int i)
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
            else if(rank[irep] > rank[jrep])
                parent[jrep] = irep;
            else
            {
                parent[jrep] = irep;
                rank[irep]++;
            }
        }
  }
    bool detectCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> parent(V);
        vector<int> rank(V,0);
        for(int i = 0;i<V;i++)
        {
            parent[i] = i;
        }
        
        for(int u = 0;u<V;u++)
        {
            for(int v : adj[u])
            {
                if(u<v)
                {
                    int urep = find(parent,u);
                    int vrep = find(parent,v);
                    
                    if(urep == vrep)
                        return true;
                    else
                    {
                        Union(parent,rank,u,v);
                    }
                }
            }
        }
        
        return false;
        
    }
};