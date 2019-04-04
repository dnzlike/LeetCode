// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.empty()) return 0;
//         sort(nums.begin(), nums.end());
//         int pre = INT_MIN, cur = 1, res = 1;
//         for (int num : nums) {
//             if ((num - pre) == 1) {
//                 cur++;
//                 res = max(res, cur);
//             }
//             else {
//                 cur = 1;
//             }
//             pre = num;
//         }
//         return res;
//     }
// };
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int val : nums) {
            if (!s.count(val)) continue;
            s.erase(val);
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};