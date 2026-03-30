class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;

        sort(nums.begin(),nums.end());  
        vector<int>counts;
        int longest =1;
        int current =1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            if(nums[i-1] + 1 ==nums[i])
                current++;
            else
            {
                longest = max(longest,current);
                current=1;
            }
        }
        return max(longest,current);
    }
};
