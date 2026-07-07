class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return dfs(nums, 0, 0, target, dp);
    }

private:
    bool dfs(vector<int>& nums, int i, int currentSum, int target,
             vector<vector<int>>& dp) {

        if (currentSum == target)
            return true;

        if (i == nums.size() || currentSum > target)
            return false;

        if (dp[i][currentSum] != -1)
            return dp[i][currentSum];

        bool take = dfs(nums, i + 1, currentSum + nums[i], target, dp);
        bool notTake = dfs(nums, i + 1, currentSum, target, dp);

        return dp[i][currentSum] = take || notTake;
    }
};