class Solution {
    int minDist = INT_MAX;
    vector<bool> sieve(int right) {
        vector<bool> isPrimes(right + 1, true);
        isPrimes[0] = isPrimes[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (isPrimes[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrimes[j] = false;
                }
            }
        }
        return isPrimes;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrimes = sieve(right);
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrimes[i]) {
                primes.emplace_back(i);
            }
        }
        if (primes.size() < 2)
            return {-1, -1};
        vector<int> ans;
        for (int i = 1; i < primes.size(); i++) {
            int dist = primes[i] - primes[i - 1];

            if (dist < minDist) {
                minDist = dist;
                ans = {primes[i - 1], primes[i]};
            }
        }
        return ans;
    }
};