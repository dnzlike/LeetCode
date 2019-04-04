class Solution {
public:
    bool isMatch(string s, string p) {
        
        if(p.empty()) return s.empty();
        if(p.size() == 1) {
            return p[0] == '*' || (s.size() == 1 && (s[0] == p[0] || p[0] == '?'));
        }
        if(p[0] == '*') {
            int count = 1;
            while(count < p.size() && p[count] == '*') {
                count++;
            }
            for(int i = 0; i < s.size(); i++) {
                if(isMatch(s.substr(i), p.substr(count))) return true;
            }
            return false;
        }
        else {
            if(s.empty()) return false;
            return (s[0] == p[0] || p[0] == '?') && isMatch(s.substr(1), p.substr(1));
        }
    }
};