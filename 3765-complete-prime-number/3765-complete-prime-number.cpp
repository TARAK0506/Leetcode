class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    bool completePrime(int num) {
        int digits = log10(abs(num)) + 1;
        for (int i = 1; i <= digits; i++) {
            int prefix = num / (int)pow(10, digits - i);
            if (!isPrime(prefix))
                return false;
        }
        for (int i = 1; i <= digits; i++) {
            int suffix = num % (int)pow(10, i);
            if (!isPrime(suffix))
                return false;
        }
        return true;
    }
};