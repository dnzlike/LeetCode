class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;
        string res = "", tmp;
        path += "/";
        for (int i = 1; i < path.size(); i++) {
            if (path[i] == '/') {
                if (tmp == "..") {
                    if (!paths.empty()) paths.pop();
                }
                else if (tmp == ".") {}
                else {
                    if (!tmp.empty()) paths.push(tmp);
                }
                tmp = "";
            }
            else {
                tmp += path[i];
            }
        }
        while (!paths.empty()) {
            // if (!paths.top().empty()) {
                res = "/" + paths.top() + res;
            // }
            paths.pop();
        }
        if (res.empty()) res = "/";
        return res;
    }
};