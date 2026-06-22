class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int c = newInterval[0];
        int d = newInterval[1];
        for(auto & interval: intervals)
        {
            int a = interval[0];
            int b = interval[1];

            // completely before
            if(b <c)
            {
                ans.push_back(interval);
            }
            else if(a > d)
            {
                ans.push_back({c,d});
                c=a;
                d=b;
            }
            else
            {
                c = min(a,c);
                d = max(b,d);
            }
        }
        ans.push_back({c,d});
        return ans;
    }
};
