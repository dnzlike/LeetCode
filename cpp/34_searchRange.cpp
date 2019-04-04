/*
 * 或者可以两次二分查找， 第一次找左边界， 第二次找右边界
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(nums.empty()) return res;
        int left = 0, right = nums.size() - 1;
        if (target < nums[left] || target > nums[right]) return res;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid, right = mid;
                while (nums[left] == target && left >= 0) {
                    res[0] = left;
                    left--;
                }
                while (nums[right] == target && right <= (nums.size() - 1)) {
                    res[1] = right;
                    right++;
                }

                return res;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
            
        }
        return res;
    }
};