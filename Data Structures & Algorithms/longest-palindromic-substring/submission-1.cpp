class Solution {
public:
    string longestPalindrome(string s) {
        int start =0;
        int maxLen = 0;
        int n = s.size();

        vector<vector<bool>> isPalindrome(n , vector<bool>(n,false));

        for(int left= n-1;left>=0; left--)
        {
            for(int right= left ; right < n ; right++)
            {
                if(s[left] == s[right] && (right - left <=2 || isPalindrome[left +1][right -1]))
                {
                    isPalindrome[left][right] = true;

                    if(right - left +1 > maxLen)
                    {
                        start = left;
                        maxLen = right -left +1;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
