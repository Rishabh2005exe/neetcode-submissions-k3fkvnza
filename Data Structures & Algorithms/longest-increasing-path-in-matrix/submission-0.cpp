class Solution {
    vector<vector<int>> dp;
    int m,n;
    vector<pair<int,int>> dir = {{1,0} ,{-1,0} ,{0,1},{0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m , vector<int>(n,0));

        int ans = 0;
        for(int i=0 ; i< m ; i++)
        {
            for(int j = 0 ;j <n ; j++)
            {
                ans = max(ans , dfs(i,j,matrix));
            }
        }
        return ans;
    }
    int dfs(int i , int j , vector<vector<int>>& matrix)
    {
        if(dp[i][j] != 0)
            return dp[i][j];

        int ans =1;

        for(auto [dx,dy]: dir)
        {
            int ni = i + dx;
            int nj = j + dy;

            if(ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j])
            {
                ans = max(ans , 1 + dfs(ni,nj , matrix));
            }
        }
        return dp[i][j] = ans;
    }
};
