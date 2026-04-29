class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26,0) , win(26,0);
        for(char c:s1)
            need[c-'a']++;
        int k = s1.size();

        for(int i=0; i<s2.size() ; i++)
        {
            win[s2[i] -'a']++;

            if(i>=k)
                win[s2[i-k] -'a']--;
            if(win == need)
                return true;
        }
        return false;
    }
};
