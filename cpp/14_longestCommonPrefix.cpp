class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string res;
        bool exist = true;
        int i = 0, n = strs[0].size();
        while(i < n && exist) {
            for(int j = 1; j < strs.size(); j++) {
                if(!strs[j][i] || (strs[j][i] != strs[0][i])) {
                    exist = false;
                    break;
                }
            }
            if(exist) {
                res = res + strs[0][i];
            }
            i++;
        }
        return res;
    }
};