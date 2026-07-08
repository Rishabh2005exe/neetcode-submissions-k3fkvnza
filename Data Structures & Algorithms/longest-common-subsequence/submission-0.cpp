class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n , vector<int>(m,-1));
        return dfs(0,0,text1,text2,dp);
    }
    int dfs(int i,int j , string& text1 , string& text2 ,vector<vector<int>>& dp )
    {
        int n = text1.size();
        int m = text2.size();
        if(i==n || j == m)
        {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + dfs(i+1 ,j+1,text1,text2,dp);
        return dp[i][j] = max(dfs(i+1 , j ,text1,text2,dp) , dfs(i,j+1 ,text1,text2,dp));
    }
};
