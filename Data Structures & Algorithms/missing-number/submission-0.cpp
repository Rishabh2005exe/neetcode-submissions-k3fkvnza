class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans =0;
        int n = nums.size();
        while(n)
        {
            ans ^=n;
            n--;
        }
        for(int i =0;i< nums.size() ; i++)
        {
            ans ^=nums[i];
        }
        return ans;
    }
};
