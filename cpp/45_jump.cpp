// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if (nums.empty()) return 0;
//         int res = 0;
//         return search(nums, 0, res);
//     }
    
//     int search(vector<int>& nums, int i, int res) {
//         if (i > (nums.size() - 1)) return nums.size();
//         if (i == (nums.size() - 1)) return res;
//         res++;
//         int tmp = 0;
//         for (int j = nums[i]; j >= 1; j--) {
//             if (nums[i] >= (nums.size() - i - 1)) return res;
//             tmp = min(search(nums, i + j, res), tmp);
//         }
//         return tmp;
//     }
// };

// 多了很多重复步骤

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0, cur = 0;
        while (cur < n - 1) {
            ++res;
            int pre = cur;
            for (; i <= pre; ++i) {
                cur = max(cur, i + nums[i]);
            }
            if (pre == cur) return -1; // May not need this
        }
        return res;
    }
};