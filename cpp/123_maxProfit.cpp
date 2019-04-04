class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        vector<int> trades;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] <= prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
            else {
                if (res != 0) trades.push_back(res);
                res = 0;
            }
        }
        trades.sort(trades.begin(), trades.end());
        int n = trades.size();
        if (n >= 2) return trades[n - 1] + trades[n - 2];
        else if (n == 1) return trades[0];
        else return 0;
    }
};