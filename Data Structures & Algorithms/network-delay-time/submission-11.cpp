class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INT_MAX);
        dist[k-1]=0;
        for(int i=0;i<n-1;i++)
        {
            for(const auto& time:times)
            {
                int source=time[0]-1;
                int dest=time[1]-1;
                int weight=time[2];
                if(dist[source]!=INT_MAX && dist[source]+weight<dist[dest])
                {
                    dist[dest]=dist[source]+weight;
                }
            }
        }
                int maxDist = *max_element(dist.begin(), dist.end());
                return maxDist == INT_MAX ? -1 : maxDist;
    }
};
