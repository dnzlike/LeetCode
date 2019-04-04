class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i]) > 1 && m[target - nums[i]] != i) [
                res.push_back(m[target - nums[i]]);
                res.push_back(i);
                break;
            ]
        }
        return res;
    }
};