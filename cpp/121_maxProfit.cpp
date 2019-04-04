class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, m = INT_MAX;
        for (int price : prices) {
            m = min(price, m);
            res = max(price - m, res);
        }
        return res;
    }
};