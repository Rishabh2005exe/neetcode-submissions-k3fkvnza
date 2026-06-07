class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int idx , vector<int>& nums  , vector<int>& curr)
    {
        ans.push_back(curr);
        for(int i= idx; i<nums.size();i++)
        {
            if( i> idx && nums[i] == nums[i-1] )
                continue;
            curr.push_back(nums[i]);
            dfs(i+1,nums,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        dfs(0,nums,curr);
        return ans;
    }
};
