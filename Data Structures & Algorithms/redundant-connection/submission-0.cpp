class Solution {
public:
    vector<int>parent,rank;
    int find(int x)
    {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1 , 0);
        for(int i=1;i<n+1 ; i++)
            parent[i] =i;
        for(auto& e : edges)
        {
            int u = e[0];
            int v = e[1];

            int pu = find(u);
            int pv = find(v);

            if(pu == pv)
                return e;
            else if(pu != pv)
            {
                if(rank[pu] < rank[pv])
                    swap(pu ,pv);
                parent[pv] = pu;
                if(rank[pu] == rank[pv])
                    rank[pu]++;
            }
        }
        return {};
    }
};
