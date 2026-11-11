class Solution {
    vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        int time=0;
        while(!q.empty() && fresh>0)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node=q.front();q.pop();
                for(auto dir:directions)
                {
                    int r=node.first+dir[0];
                    int c=node.second+dir[1];
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1)
                    {
                        grid[r][c]=2;q.push({r,c});fresh--;
                    }
                }
            }time++;
        }
        return fresh==0?time:-1;
    }
};
