class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int previousMax = nums[0];
        int previousMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            int tempMax = previousMax;
            int tempMin = previousMin;

            previousMax = max({num, num * tempMax, num * tempMin});
            previousMin = min({num, num * tempMax, num * tempMin});

            ans = max(ans, previousMax);
        }

        return ans;
    }
};