class custom_function_euc_dist{
    public:
        bool operator()(pair<int ,int>a , pair<int,int>b)
        {
            return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
        }
};


class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        custom_function_euc_dist>pq;

        for(auto x:points)
        {
            pq.push({x[0],x[1]});

            if(pq.size() >k)
                pq.pop();
        }
        vector<vector<int>>ans;

        while(!pq.empty())
        {
            ans.push_back({pq.top().first , pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
