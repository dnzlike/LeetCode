class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteDFS(num, 0, res);
        return res;
    }

    void permuteDFS(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(num);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permuteDFS(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};