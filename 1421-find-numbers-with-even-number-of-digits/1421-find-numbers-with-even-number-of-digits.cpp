class Solution {
public:
    bool findnoofDigits(int num) {
        int cnt = 0;
        while (num) {
            cnt++;
            num /= 10;
        }
        return cnt % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (auto& num : nums) {
            if (findnoofDigits(num))
                cnt++;
        }
        return cnt;
    }
};