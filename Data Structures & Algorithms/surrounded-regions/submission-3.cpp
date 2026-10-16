class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int ROWS=board.size();
        int COLS=board[0].size();
        
        queue<pair<int,int>> q;
        //flip edge zeroes to T
        for(int r=0;r<ROWS;r++)
        {
            if(board[r][0]=='O')
            {
                board[r][0]='T';
                q.push({r,0});
            }
            if(board[r][COLS-1]=='O')
            {
                board[r][COLS-1]='T';
                q.push({r,COLS-1});
            }
        }
        for(int c=0;c<COLS;c++)
        {
            if(board[0][c]=='O')
            {
                board[0][c]='T';
                q.push({0,c});
            }
            if(board[ROWS-1][c]=='O')
            {
                board[ROWS-1][c]='T';
                q.push({ROWS-1,c});
            }
        }

        while(!q.empty())
        {
            auto node=q.front();q.pop();

            for(int i=0;i<4;i++)
            {
                int nr=node.first+directions[i][0];
                int nc=node.second+directions[i][1];
                if(nr>=0 && nr<=ROWS-1 && nc>=0 && nc<=COLS-1 && board[nr][nc]=='O')
                {
                    board[nr][nc]='T';
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<ROWS;i++)
        {
            for(int j=0;j<COLS;j++)
            {
                if(board[i][j]=='T')
                {
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }

    }
};
