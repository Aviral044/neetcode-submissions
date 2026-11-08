class Solution {
public:
    vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int result=0;
        int m=grid.size();int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty() && fresh>0)
        {
            int qsize=q.size();
            for(int i=0;i<qsize;i++)
            {
                pair<int,int> node=q.front();q.pop();
                for(auto& dir:directions)
                {
                    int r=node.first+dir[0];
                    int c=node.second+dir[1];
                    if(r>=0 && c>=0 && r<m && c<n &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
            result++;
        }
        if(fresh==0)
        {
            return result;
        }
        return -1;
    }
};
