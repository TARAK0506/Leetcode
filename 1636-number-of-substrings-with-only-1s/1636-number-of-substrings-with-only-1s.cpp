class Solution {
public:
    long long const MOD = 1e9 + 7;
    int numSub(string s) {
        long long n = s.length(), ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                cnt++;
            else if (s[i] == '0') {
                ans += ((cnt * (cnt + 1)) / 2 ) % MOD;
                cnt = 0;
            }
        }
        return ans + (cnt * (cnt + 1)) / 2 % MOD;
    }
};