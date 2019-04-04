class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int t = res.size();
            for (int j = 0; j < t; j++) {
                vector<int> tmp;
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};