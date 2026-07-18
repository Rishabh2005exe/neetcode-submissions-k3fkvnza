class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end() ,0);

        if(sum%2 !=0)
            return false;

        int target = sum/2;
        unordered_set<int> reachable = {0};

        for(int i = nums.size() -1 ; i >=0 ;i --)

        {
            unordered_set<int> next = reachable;
            for(int s: reachable)
            {
                if(s + nums[i] == target)
                    return true;

                next.insert(s + nums[i]);
            }
            reachable = move(next);
        }
        return reachable.count(target);
    }
};
