class Solution {
  public:
    void DFS(vector<vector<char>>&grid,vector<vector<bool>>&visited,int r,int c,int &n, int &m)
    {
        visited[r][c] = true;
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};
        
        for(int i = 0;i<8;i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr>= 0 && nr<n &&
                nc>=0 && nc<m &&
                grid[nr][nc]=='L' &&
                visited[nr][nc]==false)
                {
                    DFS(grid,visited,nr,nc,n,m);
                }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]=='L' && visited[i][j] == false)
                {
                    count++;
                    DFS(grid,visited,i,j,n,m);
                }
            }
        }
        return count;
    }
};