class Solution {
public:
    long long computeGCD(long long a, long long b) {
        if (b == 0)
            return a;
        return computeGCD(b, a % b);
    }
    long long maxPairStrength(vector<int>& nums) {
        long long n = nums.size(), maxStrength = 0;
        for (long long i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long GCD =
                    computeGCD(nums[i], nums[j]) * computeGCD(nums[i], nums[j]);
                long long val = (1LL * nums[i] * 1LL * nums[j]);
                maxStrength = max(maxStrength, val / GCD);
            }
        }
        return maxStrength;
    }
};