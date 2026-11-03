class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++)
        {
            string a=equations[i][0];
            string b=equations[i][1];
            adj[a].push_back({b,values[i]});
            adj[b].push_back({a,(1.0/values[i])});
        }
        vector<double> res;
        for(auto q:queries)
        {
            string src=q[0];
            string target=q[1];
            unordered_set<string> visited;
            res.push_back(dfs(src,target,adj,visited));
        }
        return res;
    }
    double dfs(string& src,string& target,auto& adj,auto& visited)
    {
        if(!adj.count(src) || !adj.count(target))
        {
            return -1.0;
        }
        if(src==target)
        {
            return 1.0;
        }
        visited.insert(src);

        for(auto& [nei,weight]:adj[src])
        {
            if(!visited.count(nei))
            {
                double result=dfs(nei,target,adj,visited);
                if(result!=-1.0)
                {
                    return weight*result;
                }
            }
        }
        return -1.0;
    }
};