class Solution {
public:
    bool isMatch(string s, string p) {
        //p is empty, s should be empty
        if(p.empty()) return s.empty();
        //p has only one char
        if(p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        //p[1] != '*'
        if(p[1] != '*') {
            if(s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        // p[1] == '*'
        // "ac" "a*c"
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            // "ac" "a*ac"
            if(isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        // "cd" "a*cd"
        return isMatch(s, p.substr(2));
    }
};