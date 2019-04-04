// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size(), n = board[0].size();
//         if (m == 0 || n == 0 || (m * n) < word.size()) return false;
//         vector<vector<int>> visited(m, vector<int>(n, 0));
//         bool res = false;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == word[0]) {
//                     visited[i][j] = 1;
//                     if(existDFS(board, m, n, i, j, word.substr(1), visited)) return true;
//                     visited[i][j] = 0;
//                 }
//             }
//         }
//         return false;
//     }

//     bool existDFS(vector<vector<char>>& board, int m, int n, int i, int j, string word, vector<vector<int>>& visited) {
//         if (word.empty()) return true;
//         if(i >= 1 && board[i - 1][j] == word[0] && visited[i - 1][j] == 0) {
//             visited[i - 1][j] = 1;
//             if(existDFS(board, m, n, i - 1, j, word.substr(1), visited)) return true;
//             visited[i - 1][j] = 0;
//         }
//         if(j <= (n - 2) && board[i][j + 1] == word[0] && visited[i][j + 1] == 0) {
//             visited[i][j + 1] == 1;
//             if(existDFS(board, m, n, i, j + 1, word.substr(1), visited)) return true;
//             visited[i][j + 1] == 0;
//         }
//         if(i <= (m - 2) && board[i + 1][j] == word[0] && visited[i + 1][j] == 0) {
//             visited[i + 1][j] == 1;
//             if(existDFS(board, m, n, i + 1, j, word.substr(1), visited)) return true;
//             visited[i + 1][j] == 0;
//         }
//         if(j >= 1 && board[i][j - 1] == word[0] && visited[i][j - 1] == 0) {
//             visited[i][j - 1] == 1;
//             if(existDFS(board, m, n, i, j - 1, word.substr(1), visited)) return true;
//             visited[i][j - 1] == 0;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
        visited[i][j] = true;
        bool res = search(board, word, idx + 1, i - 1, j, visited) 
                 || search(board, word, idx + 1, i + 1, j, visited)
                 || search(board, word, idx + 1, i, j - 1, visited)
                 || search(board, word, idx + 1, i, j + 1, visited);
        visited[i][j] = false;
        return res;
    }
};