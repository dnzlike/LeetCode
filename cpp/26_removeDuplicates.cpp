class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 0, j = 0, m = nums[0];
        for(; i < nums.size(); i++) {
            if(nums[i] == m) {
                nums[j] = nums[i];
            }
            else {
                j++;
                nums[j] = nums[i];
                m = nums[i];
            }
        }
        return j + 1;
    }
};