class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0, gap = 0;
        bool flag = false;
        if (n == 1)
            return 0;
        while (n) {
            if ((n & 1) == 1) {
                maxDist = max(maxDist, gap);
                gap = 1;
                flag = true;
            } else {
                if (flag)
                    gap++;
            }
            n >>= 1;
        }
        return maxDist;
    }
};