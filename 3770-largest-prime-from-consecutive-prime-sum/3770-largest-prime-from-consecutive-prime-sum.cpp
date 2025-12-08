class Solution {
public:
    vector<bool> is_prime;
    void sieve(int n) {
        is_prime.assign(n + 1, true);
        is_prime[0] = false, is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
    }
    int largestPrime(int n) {
        int sum = 0, ans = 0;
        sieve(n);
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                sum += i;
                if (sum > n) {
                    break;
                }
                if (is_prime[sum]) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
};