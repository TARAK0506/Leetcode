class Solution {
public:
    bool check(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        for (int i = 0; i <= 9; i++) {
            if (freq[i] != 0 && freq[i] != i)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while (n < 1e7) {
            n++;
            if (check(n)) {
                return n;
            }
        }
        return 0;
    }
};