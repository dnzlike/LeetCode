class Solution {
public:
    int myAtoi(string str) {
        int n = str.size(), i = 0, res = 0;
        bool neg = false;
        while(i < n && str[i] == ' '){
            i++;
        }
        if(str[i] == '-'){
            neg = true;
            i++;
        }
        else if(str[i] == '+'){
            i++;
        }
        while(i < n && str[i] >= '0' && str[i] <= '9'){
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] > '7')){
                return neg ? INT_MIN : INT_MAX;
            }
            res = res * 10 + str[i] - '0';
            i++;
        }
        return neg ? -res : res;
    }
};