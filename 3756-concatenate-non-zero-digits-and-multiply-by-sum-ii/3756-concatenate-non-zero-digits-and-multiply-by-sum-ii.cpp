using ll = long long;
class Solution {
    ll m, q;
    const ll MOD = 1e9 + 7;
    vector<int> answer;

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        m = s.length(), q = queries.size();
        answer.resize(q, 0);
        vector<ll> power(m + 1, 1);
        vector<ll> count(m + 1, 0);
        vector<ll> digits(m, 0);
        vector<ll> prefixNum(m + 1, 0);
        vector<ll> prefixSum(m + 1, 0);
        auto compute = [&]() {
            for (int i = 1; i <= m; i++) {
                int digit = s[i - 1] - '0';
                digits[i - 1] = digit;
                prefixSum[i] = prefixSum[i - 1] + digit;
                prefixNum[i] =
                    (digit > 0 ? (prefixNum[i - 1] * 10 + digit) % MOD
                               : prefixNum[i - 1]);
                count[i] = (digit > 0 ? count[i - 1] + 1 : count[i - 1]);
                power[i] = (1LL * power[i - 1] * 10) % MOD;
            }
        };
        compute();
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            ll rangeSum = (prefixSum[r + 1] - prefixSum[l]) % MOD;
            ll nonZeros = count[r + 1] - count[l];
            ll rangeNum =
                (prefixNum[r + 1] - prefixNum[l] * power[nonZeros]) % MOD;
            if (rangeNum < 0)
                rangeNum += MOD;
            answer[i] = (rangeSum * rangeNum) % MOD;
        }
        return answer;
    }
};