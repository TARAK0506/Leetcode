class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n = prices.size(), ans = n, cnt = 0;
        long long j = 1;
        while (j < n) {
            if (prices[j - 1] - prices[j] == 1) {
                cnt++;
            } else {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
            j++;
        }
        ans += cnt * (cnt + 1) / 2;
        return ans;
    }
};
