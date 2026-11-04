class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> adj(n);
        //building the adjency list
        vector<int> edgecnt(n);
        for(auto& edge:edges)
        {
            adj[edge[0]].insert(edge[1]);edgecnt[edge[0]]++;
            adj[edge[1]].insert(edge[0]);edgecnt[edge[1]]++;
        } 
        queue<int> q;//queue for toposort
        //seed the queue
        for(int i=0;i<n;i++)
        {
            if(edgecnt[i]==1)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            if(n<=2){
                break;
            }
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int node=q.front();q.pop();n--;
                for(auto& nei:adj[node])
                {
                    edgecnt[nei]--;
                    if(edgecnt[nei]==1)
                    {
                        q.push(nei);
                    }
                }
            }
        }
        if (n <= 2) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front());
                    q.pop();
                }
                return result;
        }
        return {};

        

    }
};