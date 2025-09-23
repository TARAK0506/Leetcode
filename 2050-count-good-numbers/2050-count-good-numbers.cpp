class Solution {
public:
    const int MOD = 1e9 + 7;
    long long binpow(long long base, long long exponent) {
        base = base % MOD;
        long long result = 1;
        while (exponent > 0) {
            if (exponent & 1)
                result = result * base % MOD;
            base = base * base % MOD;
            exponent >>= 1;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long even = binpow(5, (n + 1) / 2);
        long long odd = binpow(4, (n / 2));
        return even * odd % MOD;
    }
};