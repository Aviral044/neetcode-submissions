class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        dfs(board,0,n);
        return res;
    }
    void dfs(vector<string>& board,int r,int n)
    {
        if(r==n)
        {
            res.push_back(board);return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,r,i,n))
            {
                board[r][i]='Q';
                dfs(board,r+1,n);
                board[r][i]='.';
            }
        }
    }
    bool isSafe(vector<string>& board, int r, int c, int n) {
        for (int i = r - 1; i >= 0; i--)                          // column
            if (board[i][c] == 'Q') return false;
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)  // up-left
            if (board[i][j] == 'Q') return false;
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)   // up-right
            if (board[i][j] == 'Q') return false;
        return true;
    }

};
