class Solution {
public:
    int countSubstrings(string s) {
        int start =0;
        int maxLen = 0;
        int n = s.size();
        int count=0;
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
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
