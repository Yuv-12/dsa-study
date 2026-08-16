class Solution {
  public:
  void DFS(int u, vector<vector<int>>&adj,vector<int>&disc,
                vector<int>&low,vector<bool>&instack,stack<int>&st,
                int &timer,vector<vector<int>>&ans)
    {
        disc[u] = low[u] = timer++;
        st.push(u);
        instack[u] = true;
        for(int v : adj[u])
        {
            if(disc[v]==-1)
            {
                DFS(v,adj,disc,low,instack,st,timer,ans);
                low[u] = min(low[u],low[v]);
            }
            else if(instack[v])
            {
                low[u] = min(low[u],disc[v]);
            }
        }
        if(disc[u]==low[u])
        {
            vector<int>component;
            while(true)
            {
                int node = st.top();
                st.pop();
                instack[node] = false;
                component.push_back(node);
                if(node==u)
                    break;
            }
            sort(component.begin(),component.end());
            ans.push_back(component);
        }
    }           
    vector<vector<int>> tarjans(int V, vector<vector<int>>& adj) {
        // code here
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        stack<int> st;
        vector<bool>instack(V,false);
        int timer = 0;
        vector<vector<int>>ans;
        for(int i = 0;i<V;i++)
        {
            if(disc[i]==-1)
            {
                DFS(i,adj,disc,low,instack,st,timer,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};