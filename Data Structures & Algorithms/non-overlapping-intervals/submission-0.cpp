class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int count =0;
        vector<int>current = intervals[0];
        for(int i=1;i<intervals.size() ; i++)
        {
            int a  = intervals[i][0];
            int b = intervals[i][1];

            if(a >= current[1])
                current = intervals[i];
            //overlap
            else
            {
                count++;
                current[1] = min(intervals[i][1] , current[1]);
            }
        }
        return count;
    }
};
