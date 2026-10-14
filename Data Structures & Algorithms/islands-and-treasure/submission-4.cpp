class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS=grid.size();int COLS=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<ROWS;i++)
        {
            for(int j=0;j<COLS;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty())
        {
            auto node=q.front();
            int row=node.first;
            int col=node.second;
            q.pop();

            for(int i=0;i<directions.size();i++)
            {
                int nr=row+directions[i][0];
                int nc=col+directions[i][1];

                if(nr>=0 && nc>=0 && nr<ROWS && nc<COLS && grid[nr][nc]==INT_MAX)
                {
                    q.push({nr,nc});
                    grid[nr][nc]=grid[row][col]+1;
                }
            }
        }
    }
};
