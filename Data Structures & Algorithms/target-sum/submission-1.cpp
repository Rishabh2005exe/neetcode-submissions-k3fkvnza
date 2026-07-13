class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int> , int>dp;
        return dfs(0,0, target,nums,dp);
    }
    int dfs(int index , int currentSum ,int target , vector<int>& nums , map<pair<int,int> , int> &dp)
    {
        if (index == nums.size())
             return currentSum == target;

        if(dp.count({index , currentSum}))
            return dp[{index , currentSum}];

        int add = dfs(index+1 , currentSum +nums[index] , target , nums , dp);
        int subtract = dfs(index+1 ,currentSum - nums[index] , target , nums , dp);

        return dp[{index , currentSum}] = add + subtract;

    }
};
