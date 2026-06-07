class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string&s, int l, int r)
    {
        while(l <r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void dfs(int start , string &s, vector<string>&curr)
    {
        if(start == s.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int end = start ;end <s.size() ; end++)
        {
            if(isPalindrome(s,start,end))
            {
                curr.push_back(s.substr(start,end - start +1));
                dfs(end +1 ,s,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(0, s, curr);
        return ans;
    }
};
