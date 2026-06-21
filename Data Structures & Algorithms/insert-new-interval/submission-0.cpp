class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int c = newInterval[0];
        int d = newInterval[1];

        for (auto& interval : intervals) {
            int a = interval[0];
            int b = interval[1];

            // Completely before
            if (b < c) {
                ans.push_back(interval);
            }
            // Completely after
            else if (a > d) {
                ans.push_back({c, d});

                c = a;
                d = b;
            }
            // Overlap
            else {
                c = min(c, a);
                d = max(d, b);
            }
        }

        ans.push_back({c, d});
        return ans;
    }
};