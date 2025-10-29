class Solution {
public:
    bool checkSetBits(int n) {
        while (n > 0) {
            if ((n & 1) == 0)
                return false;
            n = n >> 1;
        }
        return true;
    }
    int smallestNumber(int n) {
        for (int i = n; i <= 1024; i++) {
            if (checkSetBits(i))
                return i;
        }
        return 0;
    }
};