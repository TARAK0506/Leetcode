class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minimal_length = INT_MAX;
        int i = 0, j = 0, n = nums.size();
        int sum = 0;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                minimal_length = min(minimal_length, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minimal_length = (minimal_length == INT_MAX ? 0 : minimal_length);
    }
};