class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int idx , vector<int>& nums , vector<int>& curr)
    {
        if(idx == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        // include nums[idx]
        curr.push_back(nums[idx]);
        dfs(idx +1,nums,curr);
        // backtrack
        curr.pop_back();

        // exclude nums[idx]
        dfs(idx +1 ,nums,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        dfs(0,nums,curr);
        return ans;
    }
};
