class Solution {
public:
    int dist(vector<int>& a , vector<int>& b)
    {
        return abs( a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int>minDist(n ,INT_MAX);
        vector<bool> visited(n,false);

        minDist[0] = 0;
        int ans =0;

        for(int i=0 ; i< n ; i++)
        {
            int u =-1;

            for(int j=0; j<n ; j++)
            {
                if(!visited[j]  && (u== -1  || minDist[j] < minDist[u]))
                    u =j;
            }
            visited[u] = true;
            ans += minDist[u];

            for(int v =0 ; v<n ; v++)
            {
                if(!visited[v])
                    minDist[v] = min(minDist[v] , dist(points[u] , points[v]));
            }
        }
        return ans;
    }
};
