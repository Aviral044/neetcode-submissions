class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS=grid.size();int COLS=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<ROWS;i++)
        {
            for(int j=0;j<COLS;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        int time=0;
        vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty() && fresh>0)
        {
            int size=q.size();
            for(int k=0;k<size;k++)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nr=r+directions[i][0];
                    int nc=c+directions[i][1];
                    if(nr>=0 && nc>=0 && nr<ROWS && nc<COLS && grid[nr][nc]==1)
                    {
                        q.push({nr,nc});
                        fresh--;
                        grid[nr][nc]=2;
                    }
                }
            }

            time+=1;
        }
        if(fresh>0){
            return -1;
        }
        return time;
    }
};
