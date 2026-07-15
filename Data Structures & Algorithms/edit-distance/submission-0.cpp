class Solution {
public:
    vector<vector<int>>dp;
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n + 1, vector<int>(m + 1 ,-1));
        return dfs(0,0,word1 , word2 );
    }
    int dfs(int i , int j , string & word1 , string&  word2)
    {
        if(i == word1.size())
            return word2.size() -j;
        if(j == word2.size())
            return word1.size() -i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j])
            return dp[i][j] = dfs(i + 1, j + 1, word1, word2);

        int insert  =  1 + dfs(i , j+1 , word1 , word2);
        int deletes = 1 +  dfs(i+1 , j , word1 , word2);
        int replace = 1 + dfs(i +1 , j +1 , word1 , word2);

        return dp[i][j] = min({insert , deletes , replace});
    }
};
