// class Solution {
// public:
//     string minWindow(string s, string t) {
//         unordered_map<char, int> m;
//         for (int i = 0; i < t.size(); i++) {
//             m[t[i]] = -1;
//         }
//         int left = -1, right = -1, mleft = -1, mright = -1, min = 0;
//         bool exist = false;
//         for (int i = 0; i < s.size(); i++) {
//             if (m.count(s[i]) > 0) {
//                 m[s[i]] = i;
//                 if (!exist) {
//                     exist = hasExisted(m, t);
//                 }
//                 else {

//                 }
//                 right = max(right, i);
//                 left = (left == -1) ? i : min(left, i);

//             }
//         }
//         string res = "";
//         if (s.empty() || t.empty()) return res;

//         return res;
//     }

//     bool hasExisted(unordered_map<char, int>& m, string t) {
//         for (int i = 0; i < t.size(); i++) {
//             if (m[t[i]] == -1) return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};