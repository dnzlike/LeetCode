class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int cur = nums[0], len = 1, pos = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == cur) len++;
            else {
                cur = nums[i];
                len = 1;
            }
            if (len <= 2) {
                nums[pos] = nums[i];
                pos++;
            }
        }
        return pos;
    }
};