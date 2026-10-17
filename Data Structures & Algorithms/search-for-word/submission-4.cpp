class Solution {
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size(), COLS = board[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++)
                if (dfs(board, r, c, word, 0, visited))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, int r, int c, const string& word,
             int n, vector<vector<bool>>& visited) {
        if (n == word.size()) return true;   // matched every character

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()
            || visited[r][c] || board[r][c] != word[n])
            return false;

        visited[r][c] = true;                      // choose
        for (auto& d : dirs)
            if (dfs(board, r + d[0], c + d[1], word, n + 1, visited))
                return true;                       // early exit, keep visited as is
        visited[r][c] = false;                     // un-choose (backtrack)
        return false;
    }
};