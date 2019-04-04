class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        while(s.size() > 0) {
            if(s[0] == 'M') {
                s = s.substr(1);
                res += 1000;
            }
            else if(s[0] == 'C') {
                if(s[1] && s[1] == 'M') {
                    s = s.substr(2);
                    res += 900;
                }
                else if(s[1] && s[1] == 'D') {
                    s = s.substr(2);
                    res += 400;
                }
                else {
                    s = s.substr(1);
                    res += 100;
                }
            }
            else if(s[0] == 'D') {
                s = s.substr(1);
                res += 500;
            }
            else if(s[0] == 'X') {
                if(s[1] && s[1] == 'C') {
                    s = s.substr(2);
                    res += 90;
                }
                else if(s[1] && s[1] == 'L') {
                    s = s.substr(2);
                    res += 40;
                }
                else {
                    s = s.substr(1);
                    res += 10;
                }
            }
            else if(s[0] == 'L') {
                s = s.substr(1);
                res += 50;
            }
            else if(s[0] == 'I') {
                if(s[1] && s[1] == 'X') {
                    s = s.substr(2);
                    res += 9;
                }
                else if(s[1] && s[1] == 'V') {
                    s = s.substr(2);
                    res += 4;
                }
                else {
                    s = s.substr(1);
                    res += 1;
                }
            }
            else {
                s = s.substr(1);
                res += 5;
            }
        }
        return res;
    }
};