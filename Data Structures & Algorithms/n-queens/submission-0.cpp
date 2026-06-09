class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> cols;
    unordered_set<int>diag1;
    unordered_set<int>diag2;

    void dfs(int row , vector<string>& board , int n)
    {
        if(row == n)
        {
            ans.push_back(board);
            return;
        }
        for(int col = 0;col <n;col++)
        {
            if(cols.count(col) ||
            diag1.count(row -col) ||
            diag2.count(row + col))
                continue;
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row -col);
            diag2.insert(row + col);

            dfs( row +1 , board , n);

            board[row][col] ='.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row +col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));

        dfs(0,board,n);

        return ans;
    }
};
