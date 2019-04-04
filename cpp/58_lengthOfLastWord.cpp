class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i]) res++;
            else break;
        }
        return res;
    }
};