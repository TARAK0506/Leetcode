class Solution {
public:
    int smallestValue(int n) {
        int sum = 0, num = n;
        while (num % 2 == 0) {
            sum += 2;
            num /= 2;
        }
        for (int i = 3; i <= num; i++) {
            while (num % i == 0) {
                sum += i;
                num /= i;
            }
        }
        return sum == n ? n : smallestValue(sum);
    }
};