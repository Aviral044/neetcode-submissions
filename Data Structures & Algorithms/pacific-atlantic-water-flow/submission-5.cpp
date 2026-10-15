class Solution {
public:
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS=heights.size();int COLS=heights[0].size();
        vector<vector<int>> pac(ROWS,vector<int>(COLS,0));
        vector<vector<int>> atl(ROWS,vector<int>(COLS,0));

        for(int r=0;r<ROWS;r++)
        {
            dfs(heights,pac,r,0);
            dfs(heights,atl,r,COLS-1);
        }
        for(int c=0;c<COLS;c++)
        {
            dfs(heights,pac,0,c);
            dfs(heights,atl,ROWS-1,c);
        }
        vector<vector<int>> res;

        for(int i=0;i<ROWS;i++)
        {
            for(int j=0;j<COLS;j++)
            {
                if(atl[i][j] && pac[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    void dfs(auto& heights, auto& ocean, int r,int c)
    {
        ocean[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+directions[i][0];
            int nc=c+directions[i][1];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && heights[nr][nc]>=heights[r][c] && ocean[nr][nc]==0)
            {
                dfs(heights,ocean,nr,nc);
            }
        }
        
    }
};
