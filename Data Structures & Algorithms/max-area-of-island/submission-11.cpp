class Solution {
public:
    int directions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS=grid.size();int COLS=grid[0].size();
        int maxarea=0;

        for(int r=0;r<ROWS;r++)
        {
            for(int c=0;c<COLS;c++)
            {
                if(grid[r][c]==1)
                {
                int area=bfs(grid,r,c);
                maxarea=max(area,maxarea);}
            }
        }
        return maxarea;
    }
    int bfs(auto& grid,int r,int c)
    {
        queue<pair<int,int>> q;
        grid[r][c]=0;
        q.push({r,c});
        int res=1;

        while(!q.empty())
        {
            pair<int,int> node=q.front();q.pop();
            int row=node.first,col=node.second;
            for(int i=0;i<4;i++)
            {
                int nr=row+directions[i][0];
                int nc=col+directions[i][1];
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1)
                {
                    q.push({nr,nc});
                    grid[nr][nc]=0;
                    res+=1;
                }
            }
        }
        return res;
        
        
    }
};
