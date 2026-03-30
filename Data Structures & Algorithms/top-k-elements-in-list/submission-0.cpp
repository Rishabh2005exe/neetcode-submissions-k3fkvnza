class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x:nums)
        {
            freq[x]+=1;
        }
        vector<pair<int,int>>arr;
        for(const auto& p:freq)
        {
            arr.push_back({p.second,p.first});
        }
        sort(arr.rbegin(),arr.rend());
        vector<int>res;
        while(k)
        {
            res.push_back(arr[k-1].second);
            k--;
        }
        return res;
    }
};
