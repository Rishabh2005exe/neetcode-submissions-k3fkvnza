class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;

        int l = 0, r = nums.size() - 1;

        while(l <= r)
        {
            int pivot = nums[r];
            int p = l;

            for(int i = l; i < r; i++)
            {
                if(nums[i] <= pivot)
                {
                    swap(nums[i], nums[p]);
                    p++;
                }
            }

            swap(nums[p], nums[r]);

            if(p == k)
                return nums[p];

            if(p < k)
                l = p + 1;
            else
                r = p - 1;
        }

        return -1;
    }
};