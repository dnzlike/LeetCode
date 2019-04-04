class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        search(candidates, target, 0, {}, res);
        return res;
    }

    void search(vector<int>& candidates, int target, int start, vector<int> out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {res.push_back(out); return;}
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            out.push_back(candidates[i]);
            search(candidates, target - candidates[i], i + 1, out, res);
            out.pop_back();
        }
    }
};