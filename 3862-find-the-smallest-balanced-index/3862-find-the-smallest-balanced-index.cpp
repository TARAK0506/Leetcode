class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long n = nums.size(), maxVal = 1e15;
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        vector<long long> suffixProd(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            if (suffixProd[i + 1] > maxVal / nums[i]) {
                suffixProd[i] = maxVal;
            } else {
                suffixProd[i] = suffixProd[i + 1] * nums[i];
            }
        }
        for (int i = 0; i < n; i++) {
            long long leftSum = (i == 0) ? 0 : prefixSum[i - 1];
            long long rightProd = suffixProd[i + 1];
            if (leftSum == rightProd) {
                return i;
            }
        }
        return -1;
    }
};