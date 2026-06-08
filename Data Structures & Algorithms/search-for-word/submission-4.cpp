class Solution {
public:
    bool dfs(vector<vector<char>> & board , int r , int c, string& word , int idx)
    {
        if(idx == word.size())
            return true;
        if(r<0 || c <0 || r >= board.size() || c >= board[0].size())
            return false;
        if(board[r][c] != word[idx])
            return false;
        char temp =  board[r][c];
        board[r][c] = '#';
        bool found = 
            dfs(board ,r+1 , c , word , idx +1)||
            dfs(board,r-1,c,word,idx+1)||
            dfs(board , r,c-1,word,idx+1)||
            dfs(board , r, c+1, word , idx+1);
        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0; j < cols ; j++)
            {
                if(dfs(board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
};
