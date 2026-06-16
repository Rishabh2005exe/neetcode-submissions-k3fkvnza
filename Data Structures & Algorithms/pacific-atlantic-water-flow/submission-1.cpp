class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows  = heights.size();
        cols = heights[0].size();
        vector<vector<bool>>pacific(rows , vector<bool>(cols,false));
        vector<vector<bool>>atlantic(rows , vector<bool >(cols , false));
        vector<vector<int>>ans;

        for(int c=0;c<cols;c++)
            dfs(0,c,heights , pacific);
        for(int r=0;r<rows;r++)
            dfs(r,0,heights,pacific);

        for(int c= 0 ;c<cols;c++)
            dfs(rows-1 , c,heights,atlantic);
        for(int r=0 ;r<rows;r++)
            dfs(r,cols-1,heights , atlantic);

        for(int r=0; r<rows;r++)
        {
            for(int c= 0 ;c<cols;c++)
            {
                if(atlantic[r][c] && pacific[r][c])
                    ans.push_back({r,c});
            }
        }
        return ans;
    }
    void dfs(int r, int c , vector<vector<int>>& heights ,vector<vector<bool>>&  ocean )
    {
        ocean[r][c] = true;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        for(int i=0 ;i<4;i++)
        {
            int nr = r +dr[i];
            int nc = c + dc[i];

            if(nr <0 || nr >= rows || nc <0 || nc >= cols)
                continue;
            if(ocean[nr][nc])
                continue;
            if(heights[nr][nc] < heights[r][c])
                continue;
            dfs(nr,nc,heights,ocean);
        }
    }
};





