class Solution {
public:
    bool isPalindrome(string s) {
        string anm;
        for(int i=0;i<s.size();i++)
        {
            if('A' <=s[i] && s[i] <= 'Z' )
            {
                anm.push_back(tolower(s[i]));
            }
            else if ('0' <= s[i] && s[i] <= '9')
            {
                anm.push_back(s[i]);
            }
            else if ('a' <= s[i] && s[i] <= 'z')
            {
                anm.push_back(s[i]);
            }
        }
        string ranm =anm;
        reverse(ranm.begin(),ranm.end());
        return ranm == anm;
    }
};
