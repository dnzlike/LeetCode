class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res = {""};
        unordered_map<char, string> m = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string tmp;
        //res.push_back(m[digits[0]]);
        //res.push_back(m[digits[1]]);
        //return res;
        for(int i = 0; i < digits.size(); i++) {
            vector<string> t;
            for(int j = 0; j < m[digits[i]].size(); j++) {
                for(string s : res) {
                    t.push_back(s + m[digits[i]][j]);
                }
            }
            res = t;
        }
        return res;
    }

};