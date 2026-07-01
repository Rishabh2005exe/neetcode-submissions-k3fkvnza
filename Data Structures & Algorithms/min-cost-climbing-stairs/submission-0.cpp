class Solution {
public:
    vector<int>cache;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cache.resize(n,-1);
        return min(dfs(cost, n, 0), dfs(cost, n, 1));
    }
    int dfs(vector<int>& cost , int n , int i )
    {
        if(i >= n)
            return 0;
        if(cache[i] != -1)
            return cache[i];

        return cache[i] = cost[i] + min(dfs( cost,n,i+1) , dfs(cost , n , i+2)  );
    }
};
