class Solution {
public:
    int maxLenSubbarySumK(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size();
        int maxLen = -1, sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum > k) {
                sum -= nums[left];
                left += 1;
            }
            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right += 1;
        }
        return maxLen;
    }
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);
        int k = totalSum - x;
        if (totalSum < x)
            return -1;
        int len = maxLenSubbarySumK(nums, k);
        return len != -1 ? n - len : -1;
    }
};