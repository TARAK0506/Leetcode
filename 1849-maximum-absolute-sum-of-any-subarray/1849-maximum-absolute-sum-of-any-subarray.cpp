class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN, mini, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (maxi < sum) {
                maxi = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        mini = INT_MAX, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mini > sum) {
                mini = sum;
            }
            if (sum > 0) {
                sum = 0;
            }
        }
        return max(abs(mini), maxi);
    }
};