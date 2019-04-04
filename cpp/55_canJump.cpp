class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i = 0, cur = 0;
        while (cur < n - 1) {
            int pre = cur;
            for (; i <= pre; ++i) {
                cur = max(cur, i + nums[i]);
            }
            if (pre == cur) return false;
        }
        return true;
    }
};