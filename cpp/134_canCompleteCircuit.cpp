class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        for (int i = 0; i < N; i++) {
            int cur = 0;
            bool enough = true;
            for (int j = i; j < N; j++) {
                cur += (gas[j] - cost[j]);
                if (cur < 0) {
                    enough = false;
                    break;
                }
            }
            if (!enough) continue;
            for (int j = 0; j < i; j++) {
                cur += (gas[j] - cost[j]);
                if (cur < 0) {
                    enough = false;
                    break;
                }
            }
            if (enough) return i;
        }
        return -1;
    }
};