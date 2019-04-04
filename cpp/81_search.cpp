class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int num : nums) {
            if (num == target) return true
        }
        return false;
    }
};

//和第一题一样
//如果中间和右侧相等，将右侧指针往左移