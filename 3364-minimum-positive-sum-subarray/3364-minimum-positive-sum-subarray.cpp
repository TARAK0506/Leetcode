class Solution {
    int n, minSum;

public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        n = nums.size(), minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;
                if (len >= l && len <= r) {
                    minSum = min(minSum, sum > 0 ? sum : INT_MAX);
                }
            }
        }
        return minSum == INT_MAX ? -1 : minSum;
    }
};