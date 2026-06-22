class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>ans;
        vector<int>current = intervals[0];
        for(int i=1;i< intervals.size() ; i++)
        {
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(a > current[1])
            {
                ans.push_back(current);
                current[0] =a;
                current[1] = b;
            }
            else
            {
                current[1] = max(current[1] , b);
            }

        }
            ans.push_back(current);
            return ans;
    }
};
