class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, down = n - 1, left = 0, right = n - 1, i = 1;
        while (true) {
            for (int col = left; col <= right; col++) res[up][col] = val++;
            if (++up > down) break;
            for (int row = up; row <= down; row++) res[row][right] = val++;
            if (--right < left) break;
            for (int col = right; col >= left; col--) res[down][col] = val++;
            if (--down < up) break;
            for (int row = down; row >= up; row--) res[row][left] = val++;
            if (++left > right) break;
        }
        return res;
    }
};