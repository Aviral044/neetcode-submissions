class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto& pre:prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int finish=0;
        vector<int> result;
        while(!q.empty())
        {
            int node=q.front();q.pop();
            finish++;
            result.push_back(node);
            for(int nei:adj[node])
            {
                indegree[nei]--;
                if(indegree[nei]==0)
                {
                    q.push(nei);
                }
            }
        }

        if(finish!=numCourses)
        {
            return{};
        }
        reverse(result.begin(),result.end());
        return result;

    }
};
