class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            result[i] = 1;
            for(int j=0;j<nums.size();j++)
            {
                if(j==i)
                {
                    continue;
                }
                result[i]*=nums[j];
            }
        }
        return result;
    }
};
