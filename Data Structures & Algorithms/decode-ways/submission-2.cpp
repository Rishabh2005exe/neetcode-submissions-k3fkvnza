class Solution {
public:
    vector<int> ways;

    int numDecodings(string s) {
        ways.assign(s.size(), -1);
        return dfs(s, 0);
    }

    int dfs(string &s, int i) {
        if (i >= s.size())
            return i == s.size();

        if (s[i] == '0')
            return 0;

        if (ways[i] != -1)
            return ways[i];

        int ans = dfs(s, i + 1);

        if (i + 1 < s.size() &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ans += dfs(s, i + 2);
        }

        return ways[i] = ans;
    }
};