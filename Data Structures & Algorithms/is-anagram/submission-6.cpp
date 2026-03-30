class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()==0 ||t.length()==0)
        {
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
        {
            return true;
        }
        return false;
    }
};
