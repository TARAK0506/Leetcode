class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size(), minDiff = 110;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i] == 1 && nums[j] == 2) {
                    minDiff = min(minDiff, abs(i - j));
                }
            }
        }
        return minDiff == 110 ? -1 : minDiff;
    }
};