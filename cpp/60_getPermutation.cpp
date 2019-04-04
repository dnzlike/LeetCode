// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         string res, init = "123456789", nums = init.substr(0, n);
//         vector<int> out, visited(n, 0);
//         permuteDFS(nums, 0, visited, 0, k, res);
//         return res;
//     }
    
//     void permuteDFS(string& nums, int level, vector<int>& visited, int cur, int target, string& res) {
//         if (cur == target) return;
//         if (level = nums.size()) {
//             cur++;
//             return;
//         }
//         for (int i = 0, i < nums.size(); i++) {
//             if (visited[i] == 1) continue;
//             visited[i] = 1;
//             res += nums[i];
//             permuteDFS(nums, level + 1, visited, cur, target, res);
//             res.substr(0, res.size() - 1);
//             visited[i] = 0;
//         }
//     }
// };

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
        --k;
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};