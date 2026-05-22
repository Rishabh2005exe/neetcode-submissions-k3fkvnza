class custom_function_euclidian_distance{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return  pow(0 - a.first,2) + pow(0 - a.second , 2) < pow(0 - b.first,2) + pow(0 - b.second , 2);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int> ,
         vector<pair<int,int>> ,
          custom_function_euclidian_distance >pq;
        for(auto x: points)
        {
            pq.push({x[0] , x[1]});

            if(pq.size() >k )
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
