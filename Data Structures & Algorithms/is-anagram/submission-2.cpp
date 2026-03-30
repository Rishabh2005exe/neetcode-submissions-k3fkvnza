class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++)
        {
            freq[s[i] -'a']++; //incrementing in s
            freq[t[i]-'a']--;  //decrementing in t
        }
        for (int count:freq)
        {
            if(count!=0)
                return false;
        }
        return true;
    }
};