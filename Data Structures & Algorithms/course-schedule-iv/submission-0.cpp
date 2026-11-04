class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>> adj,isPrereq;
        vector<int> indegree(numCourses,0);

        for(auto i:prerequisites)//build adj list-[dependency]->[dependents] and indegree array
        {
            adj[i[0]].insert(i[1]);
            indegree[i[1]]++;
        }

        queue<int> q; //make a queue for indegree 0
        //seed it with nodes with indegree=0
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        //building prereq map
        while(!q.empty())
        {
            int node=q.front();//pop a node at front
            q.pop();
            for(int nei:adj[node])
            {
                isPrereq[nei].insert(node);
                isPrereq[nei].insert(isPrereq[node].begin(),isPrereq[node].end());
                indegree[nei]--;
                if(indegree[nei]==0)
                {
                    q.push(nei);
                }
            }
        }
        vector<bool> res;
        //queries
        for(auto i:queries)
        {
            if(isPrereq[i[1]].find(i[0])!=isPrereq[i[1]].end())
            {
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};