class Solution {
public:
    const int INF =  1e9;
    vector<vector<int>>dp;
    int coinChange(vector<int>& coins, int amount) {

        dp.assign(coins.size() , vector<int>(amount +1 , -1) );

        int ans = dfs(coins , amount,0 ,0);

        if(ans >= INF)
            return -1;
        return ans;
    }
    int dfs(vector<int>& coins, int amount , int index , int sum)
    {
        if(sum == amount)
            return 0;

        if(index== coins.size()|| sum > amount)
            return INF;


        if(dp[index][sum] != -1)
            return dp[index][sum];
        
        int take = INF;                        // step 1: default value
        if (coins[index] <= amount - sum)       // step 2: check condition
        take = 1 + dfs(coins, amount, index, sum + coins[index]);  // step 3: overwrite IF condition true        
        int notTake = dfs(coins , amount , index+1,sum);
        
        return dp[index][sum] = min(take,notTake);
    }
};
