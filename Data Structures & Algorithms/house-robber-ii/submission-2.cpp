class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>nums1(nums.begin() +1 , nums.end());
        vector<int> nums2(nums.begin() , nums.end() -1 );
        return max(nums[0] ,  max(helper(nums1)   , helper(nums2) ));
    }
private:
    int helper(vector<int>& nums)
    {
        // rob1 = dp[i-2]   , rob2 = dp[i-1]
        int rob1 = 0, rob2 = 0;
        for(int num: nums)
        {
            // dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            int newRob = max(rob1 + num , rob2);
            rob1 = rob2;  // dp[i-2] <- dp[i-1]
            rob2 = newRob;  // dp[i-1] <- dp[i]
        }
        return rob2;
    }
};
