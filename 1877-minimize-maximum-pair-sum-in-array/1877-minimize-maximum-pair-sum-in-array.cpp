class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxSum = INT_MIN, sum = 0;
        for (int i = 0; i <= n / 2; i++) {
            sum = nums[i] + nums[n - i - 1];
            if (maxSum < sum) {
                maxSum = sum;
                sum = 0;
            }
        }
        return maxSum;
    }
};