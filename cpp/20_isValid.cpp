class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> paren;
        for(int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{': paren.push(s[i]); break;
                case ')': {
                    if(paren.empty() || paren.top() != '(') return false;
                    paren.pop();
                    break;
                }
                case ']': {
                    if(paren.empty() || paren.top() != '[') return false;
                    paren.pop();
                    break;
                }
                case '}': {
                    if(paren.empty() || paren.top() != '{') return false;
                    paren.pop();
                    break;
                }
                default: break;
            }
        }
        if(!paren.empty()) return false;
        return true;
    }
};