class Solution {
public:
    int quickSelect(vector<int>& nums, int l, int r, int k)
    {
        int pivotIdx = l + rand() % (r - l + 1);

        swap(nums[pivotIdx], nums[r]);

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
            return quickSelect(nums, p + 1, r, k);

        return quickSelect(nums, l, p - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;

        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};