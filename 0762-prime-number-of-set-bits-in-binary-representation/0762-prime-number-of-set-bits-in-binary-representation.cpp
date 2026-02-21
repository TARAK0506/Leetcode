class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    int cntSetBits(int n) {
        int cnt = 0;
        while (n > 0) {
            if (n & 1 == 1)
                cnt++;
            n >>= 1;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int cntPrimes = 0;
        for (int i = left; i <= right; i++) {
            int setBits = cntSetBits(i);
            cntPrimes += isPrime(setBits);
        }
        return cntPrimes;
    }
};