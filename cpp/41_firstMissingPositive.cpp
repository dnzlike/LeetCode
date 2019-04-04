class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = 1;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 && (nums[i] == m)) m++;
        }
        return m;
    }
};