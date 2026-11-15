class Solution {
    const int MOD = 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), evenCnt = 1, oddCnt = 0;
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if ((sum & 1) == 0) {
                cnt = (cnt + oddCnt) % MOD;
                evenCnt += 1;
            } else {
                cnt = (cnt + evenCnt) % MOD;
                oddCnt += 1;
            }
        }
        return cnt % MOD;
    }
};