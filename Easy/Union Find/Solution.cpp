class Solution {
  public:
  void initialize(vector<int> &parent,int n)
  {
      for(int i = 1;i<=n;i++)
        {
            parent[i] = i;
        }
  }
  int find(vector<int>&parent,int i)
  {
      if(parent[i]==i)
        return i;
        else
            return parent[i] = find(parent,parent[i]);
  }
  void Union(vector<int> &parent,int i, int j)
  {
      int irep = find(parent,i);
      int jrep = find(parent,j);
      if(irep==jrep)
        return;
    parent[irep] = jrep;
  }
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        // code here
        vector<int> parent(n+1);
        initialize(parent,n);
        vector<int> res;
        for(int i = 0;i<queries.size();i++)
        {
            int qSize = queries[i].size();
            if(qSize==2)
            {
                res.push_back(find(parent,queries[i][1]));
            }
            else
            {
                Union(parent,queries[i][1],queries[i][2]);
            }
        }
        return res;
    }
};