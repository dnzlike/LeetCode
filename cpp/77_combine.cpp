class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> nums, out;
        for (int i = 0; i < n; i++) {
            nums.push_back(i + 1);
        }
        combineDFS(nums, 0, k, out, res);
        return res;
    }

    void combineDFS(vector<int>& nums, int level, int k, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() == k) {res.push_back(out); return;}
        for (int i = level; i < nums.size(); i++) {
            out.push_back(nums[i]);
            combineDFS(nums, i + 1, k, out, res);
            out.pop_back();
        }
    }
};