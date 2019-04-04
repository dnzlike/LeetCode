class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int start = 0, end = s.size() - 1;
        vector<string> out;
        partitionDFS(s, start, end, out, res);
        return res;
    }

    void partitionDFS(string s, int start, int end, vector<string> out, vector<vector<string>>& res) {
        if (start == end) {
            out.push_back(s.substr(start));
            res.push_back(out);
            return;
        }
        else if (start > end) {
            res.push_back(out);
            return;
        }

        for (int i = start; i <= end; i++) {
            if (isPalindrome(s, start, i)) {
                out.push_back(s.substr(start, i - start + 1));
                partitionDFS(s, i + 1, end, out, res);
                out.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start; --end;
        }
        return true;
    }
};