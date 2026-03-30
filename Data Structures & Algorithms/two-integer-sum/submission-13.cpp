class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>diff;
        for(int i=0;i<nums.size();i++)
        {
            int difference = target-nums[i];
            if(diff.find(difference)!=diff.end())
            {
                return {diff[difference],i};
            }
            diff.insert({nums[i],i});
        }
        return {};
    }
};