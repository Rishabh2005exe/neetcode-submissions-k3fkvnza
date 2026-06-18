class Solution {
public:
    vector<int>parent , rankv;
    int find(int x)
    {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rankv.resize(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        int components = n;
        for(auto& e:edges)
        {
            int u = e[0];
            int v = e[1];

            int pu =  find(u);
            int pv = find(v);

            if(pu != pv)
            {
                if(rankv[pu] < rankv[pv])
                {
                    swap(pu,pv);
                }
                parent[pv] = pu;
                if(rankv[pu] == rankv[pv])
                    rankv[pu]++;
                components--;
            }

        }
        return components;
    }
};
