class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            int t = res.size();
            for (int j = 0; j < t; j++) {
                if (i > 0 && nums[i] == nums[i - 1] && j < pre) continue;
                vector<int> tmp;
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
            pre = t;
        }
        return res;
    }
};

// pre指上一个3加在了哪些数组后面，新来的3就不需要再往它们后面加，避免重复