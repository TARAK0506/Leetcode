class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cnt = 1, rem = 1;
        if (k == 1)
            return 1;
        if (k % 2 == 0 || k % 5 == 0 || k % 6 == 0)
            return -1;
        for (int i = 1; i <= k; i++) {
            cnt++;
            rem = (rem * 10 + 1) % k;
            if (rem == 0)
                return cnt;
        }
        return -1;
    }
};