class Solution {
public:
    vector<int> grayCode(int n) {
        int level = 0;
        vector<int> res(1, 0);
        while (level < n) {
            for (int i = res.size() - 1; i >= 0; i--) {
                res.push_back(res[i] + (1 << level));
            }
            level++;
        }
        return res;
    }
};