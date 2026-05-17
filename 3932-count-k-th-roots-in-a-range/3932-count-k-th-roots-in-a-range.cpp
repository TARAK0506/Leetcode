class Solution {
public:
    long long power(long long base, int exp, long long limit) {
        long long res = 1;
        while (exp > 0) {
            res *= base;
            if (res > limit)
                return limit + 1;
            exp--;
        }
        return res;
    }
    long long lowerBound(long long val, long long r, int k) {
        long long low = 0, high = r, ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (power(mid, k, val) >= val) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    long long upperBound(long long val, long long r, int k) {
        long long low = 0, high = r, ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (power(mid, k, val) <= val) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    int countKthRoots(int l, int r, int k) {
        int cnt = 0;
        if (k == 1)
            return r - l + 1;
        long long lb = lowerBound(l, r, k);
        long long ub = upperBound(r, r, k);
        cnt = ub - lb + 1;
        return cnt;
    }
};
