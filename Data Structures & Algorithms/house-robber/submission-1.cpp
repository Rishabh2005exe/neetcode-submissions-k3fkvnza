class Solution {
public:
    vector<int> cache;
    int rob(vector<int>& nums) {
        int n = nums.size();
        cache.resize(n ,-1);

        return max(dfs(nums, n , 1) ,  nums[0] + dfs(nums,n,2));
    }
    int dfs(vector<int>& nums , int n , int i)
    {
        if(i>=n)
            return 0;
        if(cache[i] != -1)
            return cache[i];
        return cache[i] = max(dfs(nums,n,i+1)  , nums[i] +  dfs(nums,n,i+2));
    }
};
