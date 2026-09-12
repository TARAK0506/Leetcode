using ll = long long;
#define all(x) begin(x), end(x)
class Solution {
    int n, num;
    int noOfDigits;
    set<int> s;
    vector<bool> used;
    void backtrack(int noOfDigits, int num, vector<int>& digits) {
        if (noOfDigits == 3) {
            if ((num & 1) == 0) {
                s.insert(num);
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            if (num == 0 && digits[i] == 0)
                continue;
            used[i] = true;
            backtrack(noOfDigits + 1, num * 10 + digits[i], digits);
            used[i] = false;
        }
    }

public:
    int totalNumbers(vector<int>& digits) {
        n = digits.size(), num = 0;
        noOfDigits = 0;
        sort(all(digits));
        used.assign(n, false);
        backtrack(noOfDigits, num, digits);
        return s.size();
    }
};