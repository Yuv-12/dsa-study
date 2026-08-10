class Solution {
  public:
  bool DFS(vector<vector<int>> &mat,vector<vector<bool>>&visited,int r,int c,int n,int m)
  {
      if(mat[r][c]==2)
        return true;
      visited[r][c] = true;
      int dr[] = {-1,0,0,1};
      int dc[] = {0,-1,1,0};
      
      for(int i = 0;i<4;i++)
      {
          int nr = r + dr[i];
          int nc = c + dc[i];
          
          if(nr >= 0 && nr<n &&
            nc >=0 && nc<m &&
            (mat[nr][nc] == 2 || mat[nr][nc] == 3 || mat[nr][nc]==1) &&
            visited[nr][nc] == false)
            {
                if(DFS(mat,visited,nr,nc,n,m))
                    return true;
            }
      }
      return false;
  }
    bool isPathPossible(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 1)
                    return DFS(mat,visited,i,j,n,m);
            }
        }
        return false;
        
    }
};