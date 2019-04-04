class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), mm = m;
        int n = matrix[0].size();
        if (m == 1) return matrix[0];
        int i = 0;
        vector<int> res;
        while (m > 0) {
            for (int j = i; j < (n - i); j++) {
                res.push_back(matrix[i][j]);
            }
            if (m - i - 1 - i > 1) {
                for (int j = i + 1; j < (m - i - 1); j++) {
                    res.push_back(matrix[j][n - i - 1]);
                }
            }
            if (m != 1) {
                for (int j = i; j < (n - i); j++) {
                    res.push_back(matrix[mm - i - 1][n - j - 1]);
                }
            }
            if (m - i - 1 - i > 1) {
                for (int j = i + 1; j < (m - i - 1); j++) {
                    res.push_back(matrix[mm - j - 1][i]);
                }
            }

            i++;
            m -= 2;
        }
        return res;
    }
};