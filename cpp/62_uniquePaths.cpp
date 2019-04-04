// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         return pathDFS(m, n, 1, 1);
//     }

//     int pathDFS(int m, int n, int x, int y) {
//         if (m == x || n == y) return 1;
//         return pathDFS(m, n, x + 1, y) + pathDFS(m, n, x, y + 1);
//     }
// };

// 这tm超时？

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};