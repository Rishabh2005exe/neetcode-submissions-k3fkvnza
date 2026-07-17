class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i = 0 ; i<=n ; i++)
        {
            int count =0;
            uint32_t x = static_cast<uint32_t>(i);
            for(int j = 0; j< 32 ;j++)
            {
                if(x &( 1<< j))
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
