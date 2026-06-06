class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int idx , vector<int>& nums , vector<int>& curr , int target , int sum)
    {
        if(sum == target)   
        {
            ans.push_back(curr);
            return;
        }
        else if(sum >target)
            return;
    sort(nums.begin(), nums.end());

    for(int i=idx;i<nums.size();i++)
    {
        if(i > idx && nums[i] == nums[i-1])
            continue;

        curr.push_back(nums[i]);
        dfs(i + 1, nums, curr, target, sum + nums[i]);
        curr.pop_back();
    }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>curr;
        dfs(0,nums,curr,target,0);
        return ans;
    }
};
