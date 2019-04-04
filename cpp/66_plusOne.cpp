class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n - 1] == 9) {
            int i = n - 1;
            while (i >= 0) {
                if (digits[i] != 9) break;
                digits[i] = 0;
                i--;
            }
            if (i == -1) digits[i]++;
            else {
                vector<int> res(n + 1, 0);
                res[0] = 1;
                return res;
            }
            return digits;
        }
        else {
            digits[n - 1]++;
            return digits;
        }
    }
};