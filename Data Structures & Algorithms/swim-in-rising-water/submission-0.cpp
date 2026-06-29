class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist( n, vector<int>(n,INT_MAX));
        vector<vector<bool>> visited(n , vector<bool>(n,false));

        priority_queue< 
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
            >pq;
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0] ,0,0});

        vector<pair<int,int>> dir{{1,0} , {-1,0} ,{0,1} , {0,-1}};

        while(! pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int time = cur[0];
            int r = cur[1];
            int c = cur[2];

            if(visited[r][c])
                continue;
            
            visited[r][c] = true;

            if(r == n-1 && c == n-1)
                return time;

            for(auto[dr,dc] : dir)
            {
                int nr = r +dr;
                int nc = c+ dc;

                if(nr >=0 && nc >=0 && nr < n && nc <n && !visited[nr][nc])
                {
                    int newTime = max(time , grid[nr][nc]);

                    if(newTime < dist[nr][nc])
                    {
                        dist[nr][nc] = newTime;
                        pq.push({newTime , nr , nc});
                    }
                }
            }
        }
        return -1;
    }
};
