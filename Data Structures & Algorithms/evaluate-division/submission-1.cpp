class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        //building adjency list
        int i=0;
        for(auto& equation:equations)
        {
            string a=equation[0];
            string b=equation[1];
            double weight=values[i];i++;
            adj[a].push_back({b,weight});
            adj[b].push_back({a,(1/weight)});
        }
        vector<double> result;
        for(auto& query: queries)
        {
            string src=query[0];
            string dst=query[1];
            unordered_set<string> visited;
            result.push_back(dfs(src,dst,adj,visited));
        }
        return result;
    }
    double dfs(string src,string dst,auto& adj,auto& visited)
    {
        if(!adj.count(src)||!adj.count(dst))
        {
            return -1.0;
        }

        if(src==dst)
        {
            return 1.0;
        }
        visited.insert(src);
        for(auto& node:adj[src])
        {
            if(!visited.count(node.first))
            {
                string nei=node.first;
                double weight=node.second;
                double result=dfs(nei,dst,adj,visited);
                if(result!=-1.0)
                {return weight*result;}
            }
        }
        return -1.0;
    }
};