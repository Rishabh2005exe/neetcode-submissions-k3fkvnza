class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int i,j;
        int m=nums.size();
        for(i=0;i<m-1;i++)
        {
            for(j=i+1;j<m;j++)
            {
                if(nums[i]==nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
