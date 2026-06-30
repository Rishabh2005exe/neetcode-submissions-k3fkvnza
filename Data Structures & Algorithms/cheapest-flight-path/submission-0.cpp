class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});   // {cost, node, flights_used}

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int stops = curr[2];

            if (node == dst)
                return cost;

            if (stops == k + 1)
                continue;

            for (auto &nei : adj[node]) {
                int nextNode = nei.first;
                int wt = nei.second;

                if (cost + wt < dist[nextNode][stops + 1]) {
                    dist[nextNode][stops + 1] = cost + wt;
                    pq.push({cost + wt, nextNode, stops + 1});
                }
            }
        }

        return -1;
    }
};