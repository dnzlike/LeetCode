class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = {""};
        if(n == 0) return res;
        for(int i = 0; i < 2 * (n - 1); i++) {
            vector<string> tmp;
            for(string s : res) {
                tmp.push_back(s + "(");
                tmp.push_back(s + ")");
            }
            res = tmp;
        }
        vector<string> ret;
        for(int i = 0; i < res.size(); i++) {
            int par = 0;
            string str = "(" + res[i] + ")";
            bool flag = true;
            for(int j = 0; j < str.size(); j++) {
                if(str[j] == '(') {
                    par++;
                }
                else {
                    if(par == 0) {
                        flag = false;
                    }
                    else {
                        par--;
                    }
                }
            }
            if(par != 0) {
                flag = false;
            }
            if(flag) {
                ret.push_back(str);
            }
        }
        return ret;
    }
};