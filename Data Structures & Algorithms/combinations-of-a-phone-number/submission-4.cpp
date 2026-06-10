class Solution {
public:
    vector<string>ans;
    void dfs(int index , string& current , string& digits , vector<string>& mp)
    {
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        string letters = mp[digits[index]  - '0'];
        for(char ch: letters)
        {
            current.push_back(ch);
            dfs(index +1 , current , digits , mp);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string> mp ={
            "","","abc","def","ghi","jkl","mno","pqrs",
            "tuv","wxyz"
        };
        string current = "";
        dfs(0,current , digits , mp);
        return ans;
    }
};
