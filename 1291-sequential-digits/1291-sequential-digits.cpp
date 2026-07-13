#define all(x) sort(begin(x), end(x))
class Solution {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ans;

public:
    void solve(int low, int high, int digit, int num) {
        if (low <= num && num <= high) {
            ans.emplace_back(num);
        }
        if (digit > 9 || num > high)
            return;
        solve(low, high, digit + 1, num * 10 + digit);
    }
    vector<int> sequentialDigits(int low, int high) {
        int i = 1;
        while (i < digits.size()) {
            solve(low, high, i, 0);
            i++;
        }
        all(ans);
        return ans;
    }
};