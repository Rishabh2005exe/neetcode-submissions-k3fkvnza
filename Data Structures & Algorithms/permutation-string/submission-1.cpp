class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // my idea
        unordered_map<char,int>mp;

        for(char  c: s1)
            mp[c]++;
        int l=0;

        for(int r=0;r <s2.size();r++)
        {
            mp[s2[r]]--;

            while(mp[s2[r]] <0)
            {
                mp[s2[l]]++;
                l++;
            }
            if(r-l +1 == s1.size())
                return true;
        }
        return false;
    }
};
