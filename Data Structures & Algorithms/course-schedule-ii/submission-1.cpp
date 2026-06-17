class Solution {
public:
    vector<int> findOrder(int numCourses,  vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses ,0);
        vector<vector<int>> adj(numCourses);
        vector<int>finalOrder;
        for(auto& pre : prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;++i)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int finish =0;
        while(!q.empty())
        {
            int node = q.front();
            finalOrder.push_back(node);
            q.pop();
            
            finish++;
            for(int nei : adj[node])
            {
                indegree[nei]--;
                if(indegree[nei] == 0)
                {
                    q.push(nei);
                    
                }
            }
        }
        return (finish == numCourses) ? finalOrder :  vector<int>{};
    }
};
