class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int next =1;
        int curr = (s[n-1] == '0') ? 0:1;

        for(int i= n-2 ; i >=0 ;i--)
        {
            int temp=0;
            if(s[i] != '0')
            {
                temp = curr;

                if(s[i] == '1' || ( s[i] == '2' && s[i+1] <= '6'))
                    temp +=next;
            }
            next =curr;
            curr = temp;
        }
        return curr;
    }
};
