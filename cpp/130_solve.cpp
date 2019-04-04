class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') solveDFS(board, i, 0);
            if (board[i][n - 1] == 'O') solveDFS(board, i, n - 1);
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O') solveDFS(board, 0, j);
            if (board[m - 1][j] == 'O') solveDFS(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '&') board[i][j] = 'O';
            }
        }
    }

    void solveDFS(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i > m - 1 || j > n - 1) return;
        board[i][j] == '&';
        solveDFS(board, i - 1, j);
        solveDFS(board, i + 1, j);
        solveDFS(board, i, j - 1);
        solveDFS(board, i, j + 1);
    }
};

[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]