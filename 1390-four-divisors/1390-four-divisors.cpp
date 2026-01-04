class Solution {
public:
    int findDivisors(int n) {
        int sum = 0, cnt = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;
                if (i != n / i) {
                    cnt++;
                    sum += n / i;
                }
            }
        }
        return (cnt == 4 ? sum : 0);
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            sum += findDivisors(nums[i]);
        }
        return sum;
    }
};