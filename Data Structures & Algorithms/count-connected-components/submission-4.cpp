class Solution {
public:
    vector<int> parent ;
    int find(int x)
    {
        while(parent[x] != x)
            x = parent[x];
        return x;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0; i <n;i++)
        {
            parent[i] = i;
        }
        int components = n;
        for(auto & e:edges)
        {
            int u = e[0];
            int v = e[1];
            int pu = find(u);
            int pv = find(v);

            if(pu != pv)
            {
                parent[pv] = pu;
                components--;
            }

        }
        return components;

    }
};
