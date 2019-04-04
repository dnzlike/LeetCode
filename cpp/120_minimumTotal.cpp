class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else if (j == triangle[i].size() - 1) triangle[i][j] += triangle[i - 1][j - 1];
                else triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        vector<int> res = triangle.back();
        sort(res.begin(), res.end());
        return res[0];
    }
};