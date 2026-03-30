class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(int i=0;i<s.size();i++)
        {
            char n = s[i];
            if(isalnum(n))
            {
                res +=tolower(n);
            }
        }
        return res == string(res.rbegin(),res.rend());
    }
};
