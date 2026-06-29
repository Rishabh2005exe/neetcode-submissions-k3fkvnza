class Solution {
public:

    vector<int> dijkstra(int n , vector<vector<pair<int,int>>>& adj , int src)
    {
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        dist[src] =0;
        pq.push({0,src});

        while(!pq.empty())
        {
            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u])
                continue;
            for(auto [v,wt] : adj[u]){
                if(dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v]  , v});
                }
            }
        }
        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto& e:times)
        {
            int u= e[0] , v= e[1] , w  = e[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist = dijkstra(n+1 , adj ,k);

        int ans =0;

        for(int i = 1;i<n+1; i++)
        {
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans , dist[i]);
        }
        return ans;
    }
};
