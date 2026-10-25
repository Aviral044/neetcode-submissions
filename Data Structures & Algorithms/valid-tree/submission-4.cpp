class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;//each node is its own parent now
        }
    }
    int find(int node)//returns the parent of the provided node
    {
        int cur=node;
        while(cur!=parent[cur])//while the cur is not its own parent
        {
            parent[cur]=parent[parent[cur]];
            cur=parent[cur];
        }
        return cur;
    }
    bool Union(int u,int v)
    {
        int pu=find(u);
        int pv=find(v);
        if(pv==pu){
            return false;
        }

        if(rank[pu]>rank[pv])
        {
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }
        else{
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
        return true;
    }

};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1){return false;}
        DSU dsu(n);
        int comp=n;
        for(auto& edge:edges)
        {
            if(dsu.Union(edge[0],edge[1]))
            {
                comp--;
            }
            else{
                return false;
            }
        }
        return comp==1;
    }
};
