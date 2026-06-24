class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = nums[0];
        for(int i=0; i< nums.size() ; i++)
        {
            if(i > farthest)
            {
                return false;
            }
            farthest = max(farthest, i+ nums[i]);
            if(i == nums.size()-1)
                return true;
        }
        return true;
    }
};
