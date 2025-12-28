class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long n = nums.size(), prefixSum = 0, maxScore = LLONG_MIN;
        vector<int> suffixMin(n, 0);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            long long score = prefixSum - suffixMin[i + 1];
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
