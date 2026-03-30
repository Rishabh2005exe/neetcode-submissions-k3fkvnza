class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int>Setnums(nums.begin(), nums.end());

        vector<int>array(Setnums.begin(),Setnums.end());
        sort(array.begin(),array.end());

        int Maxcount=1,count=1;

        for(int i=1;i<array.size();i++)
        {
            if(array[i]==array[i-1]+1)
                count++;
            else
                count=1;
            Maxcount=max(Maxcount,count);
        }
        return Maxcount;
    }
};
