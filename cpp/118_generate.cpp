class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> pre(1, 1);
        for (int i = 0; i < numRows; i++) {
            vector<int> cur(i + 1, 1);
            for (int j = 1; j < i; j++) {
                cur[j] = pre[j - 1] + pre[j];
            }
            pre = cur;
            res.push_back(cur);
        }
        return res;
    }
};