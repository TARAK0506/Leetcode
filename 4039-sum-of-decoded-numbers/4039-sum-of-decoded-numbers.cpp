using ll = long long;
class Solution {
    const ll MOD = 1e9 + 7;

public:
    ll binExp(ll base, ll exp) {
        ll res = 1;
        while (exp) {
            if (exp & 1) {
                res = res * base % MOD;
            }
            base = base * base % MOD;
            exp >>= 1;
        }
        return res % MOD;
    }
    pair<ll, ll> formNumber(ll number, ll k) {
        int totalDigits = (int)log10(number) + 1;
        ll divisor = (ll)pow(10, totalDigits - k);
        ll prefix = number / divisor;
        ll suffix = number % divisor;
        return {prefix, suffix};
    }
    int sumDecoded(vector<long long>& nums) {
        ll sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            ll width = nums[i] % 10;
            ll di = floor(nums[i] / 10);
            auto [x, y] = formNumber(di, width);
            sum += binExp(x, y) % MOD;
        }
        return sum % MOD;
    }
};