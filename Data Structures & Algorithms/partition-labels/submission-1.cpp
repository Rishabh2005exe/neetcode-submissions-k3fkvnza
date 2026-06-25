class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last(26);
        vector<int>ans;
        for(int i=0;i<s.size();i++)
            last[s[i] - 'a'] =i;
        int end =0;
        int j=0;
        for(int i=0;i<s.size() ;i++)
        {
            end = max(end,last[s[i] -'a']);
            if(i == end)
            {
                ans.push_back(i-j+1);
                j=i+1;
            }
        }
        return ans;
    }
};
