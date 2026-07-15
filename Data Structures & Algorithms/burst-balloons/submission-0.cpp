class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n  = nums.size();

        // add virtual ballons

        nums.insert(nums.begin() , 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2 , vector<int>(n+2 , -1));

        return dfs(0 , n+1 , nums , dp);
    }
    int dfs(int left , int right , vector<int>& nums , vector<vector<int>>& dp)
    {
        if(left +1 == right)
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];

        int ans =0;

        // trying all the balloons

        for(int k = left +1 ; k< right ; k++)
        {
            int coins = nums[left]* nums[k]* nums[right]
            + dfs(left , k, nums , dp)
            + dfs(k , right , nums , dp);

            ans = max(ans , coins);
        }
        return dp[left][right] = ans;
    }
};
