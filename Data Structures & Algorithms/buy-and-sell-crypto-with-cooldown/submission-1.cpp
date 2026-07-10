class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n ,vector<int>(2,-1));
        return dfs(0,true , prices ,dp);
    }
    int dfs(int i , bool canBuy , vector<int>& prices , vector<vector<int>>& dp)
    {
        if( i>= prices.size())
            return 0;
        if(dp[i][canBuy] != -1)
            return dp[i][canBuy];
        if(canBuy)
        {
            int buy = -prices[i] + dfs(i+1 , false , prices ,dp);
            int skip = dfs(i +1 , true , prices , dp);
            return dp[i][canBuy] = max(buy , skip);
        }
        else
        {
            int sell = prices[i] + dfs(i+2 , true , prices, dp);
            int hold = dfs(i+1 , false , prices,dp);
            return dp[i][canBuy] = max(sell , hold);
        }
    }
};
