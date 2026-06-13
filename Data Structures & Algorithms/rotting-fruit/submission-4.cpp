class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh =0;
        int time =0;
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>>q;

        for(int r=0; r<rows;r++)
        {
            for(int c=0;c <cols;c++)
            {
                if(grid[r][c] == 1)
                    fresh++;
                if(grid[r][c] ==2)
                    q.push({r,c});
            }
        }
        vector<pair<int,int>> dire ={
            {1,0} , {-1,0}, {0,1} , { 0,-1}
        };
        while(fresh > 0 && !q.empty())
        {
            int length = q.size();

            for(int i= 0;i < length;i++)
            {
                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for( const auto& dir: dire)
                {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if(row >=0 && col >= 0 && row <rows && col <cols && grid[row][col] == 1 )
                    {
                        grid[row][col] =2;
                        q.push({row,col});
                        fresh--;
                    }
                        
                }
            }
            time++;
        }
        return fresh == 0? time:-1;

    }
};
