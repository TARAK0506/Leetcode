class Solution {
    int n, startIdx;

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        n = gas.size(), startIdx = 0;
        int totalGas = 0, currFuel = 0;
        for (int i = 0; i < n; i++) {
            int net = gas[i] - cost[i];
            totalGas += net;
            currFuel += net;
            if (currFuel < 0) {
                currFuel = 0;
                startIdx = i + 1;
            }
        }
        return totalGas < 0 ? -1 : startIdx;
    }
};