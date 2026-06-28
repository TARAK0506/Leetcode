class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long n = nums.size(), totalSum = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0 && k > 0; i--) {
            if (mul > 0) {
                totalSum += (long long)nums[i] * mul;
                mul -= 1;
            } else {
                totalSum += nums[i];
            }
            k--;
        }
        return totalSum;
    }
};