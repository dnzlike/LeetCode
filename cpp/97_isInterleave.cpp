// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         if ((s1.size() + s2.size()) != s3.size()) return false;
//         if ((s1.empty() && s2 == s3) || (s2.empty() && s1 == s3)) return true;
//         if (s1[0] == s3[0] && s2[0] == s3[0]) {
//             return isInterleave(s1.substr(1), s2, s3.substr(1)) || 
//                     isInterleave(s1, s2.substr(1), s3.substr(1));
//         }
//         else if (s1[0] == s3[0]) return isInterleave(s1.substr(1), s2, s3.substr(1));
//         else if (s2[0] == s3[0]) return isInterleave(s1, s2.substr(1), s3.substr(1));
//         else return false;
//     }
// };

// 超时

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<bool> > dp(n1 + 1, vector<bool> (n2 + 1, false)); 
        dp[0][0] = true;
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for (int i = 1; i <= n2; ++i) {
            dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        }
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
            }
        }
        return dp[n1][n2];
    }
};