class Solution {
public:
    vector<int> cache;

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        cache.resize(n, -1);
        int first = dfs(nums, 0, n - 1);

        cache.assign(n, -1);
        int second = dfs(nums, 1, n);

        return max(first, second);
    }

    int dfs(vector<int>& nums, int i, int end) {
        if (i >= end)
            return 0;

        if (cache[i] != -1)
            return cache[i];

        return cache[i] = max(
            dfs(nums, i + 1, end),
            nums[i] + dfs(nums, i + 2, end)
        );
    }
};