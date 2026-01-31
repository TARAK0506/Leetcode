class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0;
        int i = 0, j = 0, minSize = INT_MAX;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                minSize = min(j - i + 1, minSize);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minSize == INT_MAX ? 0 : minSize;
    }
};