class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin() , intervals.end());
        vector<pair<int,int>> q;

        for(int i=0; i <queries.size() ; i++)
        {
            q.push_back({queries[i] , i});
        }
        sort(q.begin() , q.end());
        vector<int> ans(queries.size());
        priority_queue<pair<int,int> , 
        vector<pair<int,int>>,
        greater<pair<int,int>>> minHeap;

        int i=0;

        for(auto &[query ,idx]: q)
        {
            while(i < intervals.size() && intervals[i][0] <= query)
            {
                int left = intervals[i][0];
                int right = intervals[i][1];
                int len = right - left +1;
                minHeap.push({len , right});
                i++;
            }
            while(!minHeap.empty()  && minHeap.top().second < query)
                minHeap.pop();
            if(minHeap.empty())
                ans[idx] = -1;
            else
                ans[idx] = minHeap.top().first;
        }
        return ans;
    }
};
