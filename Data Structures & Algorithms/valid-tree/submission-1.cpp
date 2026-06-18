class Solution {
public:
    bool dfs(int node , int parent , vector<vector<int>>& adj , vector<bool>& visited)
    {
        visited[node] = true;
        for(int nei : adj[node])
        {
            if(!visited[nei])
            {
                if(!dfs(nei ,node , adj , visited))
                    return false;
            }
            else if(nei != parent)
                return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
        {
            return false;
        }
        vector<vector<int>> adj(n);
        for(auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);

        if(!dfs(0,-1,adj,visited))
            return false;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                return false;
        }
        return true;
    }
};
