class Solution {
public:
    bool isPerfectSquare(int c) {
        int low = 1, high = c;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid * mid == c) {
                return true;
            } else if (mid * mid < c) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    int countTriples(int n) {
        int cnt = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c = a * a + b * b;
                if (c <= n * n && isPerfectSquare(c)) {
                    // cout << a << " " << b << " " << c << "\n";
                    cnt++;
                }
            }
        }
        return cnt;
    }
};