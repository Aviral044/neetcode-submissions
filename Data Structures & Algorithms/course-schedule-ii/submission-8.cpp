class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inorder(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inorder[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> result;
        int finished=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();finished++;
            result.push_back(node);
            for(auto& c:adj[node])
            {
                inorder[c]--;
                if(inorder[c]==0)
                {
                    q.push(c);
                }
            }
        }
        if(finished!=numCourses)
        {
            return {};
        }
        return result;
    }
};
