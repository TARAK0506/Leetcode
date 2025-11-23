class Solution {
public:
    long long reverse(int x) {
        long long n = x;
        long long rev = 0;
        while (n) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }
        return rev;
    }
    long long sumOfDigits(long long n) {
        long long sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    long long sumAndMultiply(int n) {
        long long x = 0;
        while (n) {
            if (n % 10 != 0)
                x = x * 10 + n % 10;
            n /= 10;
        }
        return reverse(x) * sumOfDigits(x);
    }
};