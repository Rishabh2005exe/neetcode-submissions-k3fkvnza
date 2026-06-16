class Solution {
public:
    int rows;
    int cols;


    void dfs(int r, int c,vector<vector<char>>& grid )
    {
        if(r<0 || c< 0 || r>=rows || c >= cols || grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        dfs(r+1 , c,grid);
        dfs(r-1 , c,grid);
        dfs(r , c+1 , grid);
        dfs(r , c-1 , grid);
    }


    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int isLands=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == '1')
                {
                    isLands++;
                    dfs(i,j,grid);
                }
            }
        }
        return isLands;
    }
};
