class DSU{
public:
    vector<int> par;
    vector<int> rank;
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
    }
    int find(int node)
    {
        while(par[node]!=node)
        {
            par[node]=par[par[node]];
            node=par[node];
        }
        return par[node];
    }
    bool Union(int n1,int n2)
    {
        int p1=find(n1);int p2=find(n2);
        int r1=rank[p1];
        int r2=rank[p2];
        if(p1==p2){return false;}
        if(r1>r2)
        {
            par[p2]=p1;
            rank[p1]+=rank[p2];
        }
        else
        {
            par[p1]=p2;
            rank[p2]+=rank[p1];
        }
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int components=n;
        DSU* d=new DSU(n);
        for(auto& edge:edges)
        {
            if(d->Union(edge[0],edge[1])==true)
            {
                components--;
            }
        }
        return components;
    }
};
