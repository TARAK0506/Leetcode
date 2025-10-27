class Solution {
public:
    int countOnes(string str) {
        int n = str.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '1')
                cnt++;
        }
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr = 0, sum = 0;
        for (int i = 0; i < bank.size(); i++) {
            int cnt = countOnes(bank[i]);
            curr = cnt;
            if (cnt != 0) {
                sum += cnt * prev;
                prev = curr;
            }
        }
        return sum;
    }
};