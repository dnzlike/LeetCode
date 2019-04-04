class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        search(candidates, target, 0, {}, res);
        return res;
    }

    void search(vector<int>& candidates, int target, int start, vector<int> out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {res.push_back(out); return;}
        for (int i = start; i < candidates.size(); i++) {
            out.push_back(candidates[i]);
            search(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};