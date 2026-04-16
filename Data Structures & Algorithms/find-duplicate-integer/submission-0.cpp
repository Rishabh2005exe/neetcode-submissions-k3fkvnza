class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>single;
        for(int num:nums)
        {
            if(single.find(num) !=single.end())
                return num;
            single.insert(num);
        }
        
    }
};
