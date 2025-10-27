class Solution {
public:
    int totalMoney(int n) {
        double weeks = n / 7, remaining_days = n % 7;
        double i = 4, sum = 0, cnt = 1, d = 1;
        if (n > 0 && n <= 7) {
            return n * (n + 1) / 2;
        }
        while (weeks--) {
            sum += 7 * i;
            i++;
            cnt++;
        }
        sum += (double)(remaining_days / 2) * (2 * cnt + (remaining_days - 1) * d);
        return sum;
    }
};