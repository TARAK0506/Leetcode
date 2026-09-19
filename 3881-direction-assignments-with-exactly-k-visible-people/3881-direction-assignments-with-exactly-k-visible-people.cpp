using ll = long long;
class Solution {
    const ll MOD = 1e9 + 7;
    ll binExp(ll base, ll exp) {
        ll res = 1;
        while (exp) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    ll modInverse(ll n) { 
        return binExp(n, MOD - 2); 
    }

public:
    vector<ll> factorial(ll N) {
        vector<ll> fact(N + 1);
        fact[0] = 1;
        for (ll i = 1; i <= N; i++) {
            fact[i] = (1LL) * (fact[i - 1] * i) % MOD;
        }
        return fact;
    }
    ll compute_nCr(ll n, ll r) {
        if (r < 0 || r > n)
            return 0;
        vector<ll> fact = factorial(n);
        ll numerator = fact[n] % MOD;
        ll denominator = fact[n - r] * fact[r] % MOD;
        ll modInv = modInverse(denominator);
        return numerator * modInv % MOD;
    }
    int countVisiblePeople(int n, int pos, int k) {
        n = n - 1;
        return 2LL * (compute_nCr(n, k)) % MOD;
    }
};