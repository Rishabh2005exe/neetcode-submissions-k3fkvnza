class Solution {
public:
    int rows;
    int cols;
    void dfs(int r, int c, vector<vector<char>>& board , vector<vector<bool>>& safe )
    {
        if(r<0 || r>= rows || c <0 || c >= cols || board[r][c] == 'X')
            return;
        if(safe[r][c])
            return;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        safe[r][c] = true;
        for(int i=0;i <4;i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            dfs(nr,nc,board,safe);
        }
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>>safe(rows, vector<bool>(cols,false));
        for(int c=0;c<cols;c++)
            dfs(0,c,board,safe);
        for(int r=0 ;r<rows;r++)
            dfs(r,0,board,safe);
        for(int c=0;c<cols;c++)
            dfs(rows-1  , c,board,safe);
        for(int r=0 ; r<rows ; r++)
            dfs(r,cols-1 , board,safe);
            
        for(int r=0;r<rows;r++)
        {
            for(int c=0; c<cols;c++)
            {
                if(safe[r][c])
                    continue;
                board[r][c] = 'X';
            }
        }
    }
};
