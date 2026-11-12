class Solution {
    int n, maxLen;

public:
    int isDecreasing(vector<int>& nums) {
        int i = 0, j = 1, maxLen = 1;
        while (j < n) {
            if (nums[j - 1] > nums[j]) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                i = j;
            }
            j += 1;
        }
        return maxLen;
    }
    int isIncreasing(vector<int>& nums) {
        int i = 0, j = 1, maxLen = 1;
        while (j < n) {
            if (nums[j - 1] < nums[j]) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                i = j;
            }
            j += 1;
        }
        return maxLen;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        n = nums.size(), maxLen = 1;
        maxLen = max(isIncreasing(nums), isDecreasing(nums));
        return maxLen;
    }
};