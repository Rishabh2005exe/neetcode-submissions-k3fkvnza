class Solution {
public:
    int rows;
    int cols;


    int dfs(int r, int c,vector<vector<int>>& grid )
    {
        if(r<0 || c< 0 || r>=rows || c >= cols || grid[r][c] == 0)
            return 0 ;
        grid[r][c] = 0;
        return 1 +  dfs(r+1 , c,grid) +
        dfs(r-1 , c,grid) +
        dfs(r , c+1 , grid) +
        dfs(r , c-1 , grid);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxArea=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 1)
                {
                    
                    maxArea = max(maxArea , dfs(i,j,grid)) ;
                }
            }
        }
        return maxArea;
    }
};

