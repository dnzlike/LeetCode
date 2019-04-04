class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        ipDFS(s, 0, "", res);
        return res;
    }

    void ipDFS(string s, int level, string out, vector<string>& res) {
        if (level == 4) {
            if (s.empty()) res.push_back(out); 
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (s.size() < i) break;
            int val = atoi(s.substr(0, i).c_str());
            if (val > 255 || (i > 1 && s[0] == '0')) break;
            ipDFS(s.substr(i), level + 1, out + s.substr(0, i) + (level == 3 ? "" : "."), res);
        }
    }
};