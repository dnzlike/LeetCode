class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        int left = 0, right = m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) right = mid - 1;
            else left = mid + 1;
        }
        int tmp = right;
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[tmp][mid] == target) return true;
            else if (matrix[tmp][mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};