class Solution {
    vector<vector<long long>> dp;
public:
    int numDistinct(string s, string t) {
        int m = s.size() , n = s.size();
        dp.assign(m+1 , vector<long long>( n+1 , -1));
        return dfs(0,0,s,t);
    }
    long long dfs(int i , int j, string& s , string& t)
    {
        if( j == t.size())
            return 1;
        if( i == s.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        long long ans = dfs(i+1 , j, s, t); // skip

        if(s[i] == t[j])
            ans += dfs(i+1 , j+1 , s ,t); // take

        return dp[i][j] = ans;
    }
};
