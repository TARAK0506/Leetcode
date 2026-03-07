class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -1 * N;
        }
        while (N > 0) {
            if ((N & 1)) {
                res *= x;
            }
            x *= x;
            N >>= 1;
        }
        return res;
    }
};