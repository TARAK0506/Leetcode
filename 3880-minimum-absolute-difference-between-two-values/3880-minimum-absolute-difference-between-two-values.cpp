class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size(), minDiff = 110;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((nums[i] == 1 && nums[j] == 2) || (nums[i] == 2 && nums[j] == 1)) {
                    minDiff = min(minDiff, abs(i - j));
                }
            }
        }
        return minDiff == 110 ? -1 : minDiff;
    }
};