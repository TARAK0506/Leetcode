class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size(), maxVal = 0;
        vector<int> prefixMax(n + 1, 0);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }
        for (int j = 0; j < n; j++) {
            if (j - k >= 0)
                maxVal = max(maxVal, nums[j] + prefixMax[j - k]);
        }
        return maxVal;
    }
};