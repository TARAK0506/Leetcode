class Solution {
public:
    vector<bool> isSieve(int n) {
        vector<bool> isPrime(n + 1, true);
        if (n >= 0)
            isPrime[0] = false;
        if (n >= 1)
            isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    int cntSetBits(int n) {
        int cnt = 0;
        while (n > 0) {
            if ((n & 1) == 1)
                cnt++;
            n >>= 1;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int cntPrimes = 0;
        vector<bool> isPrime = isSieve(100);
        for (int i = left; i <= right; i++) {
            int setBits = cntSetBits(i);
            cntPrimes += isPrime[setBits];
        }
        return cntPrimes;
    }
};