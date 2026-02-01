class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size(), minCost = INT_MAX;
        if (n == 3)
            return nums[0] + nums[1] + nums[2];
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else if (nums[i] < secondMin && nums[i] != firstMin) {
                secondMin = nums[i];
            }
        }
        minCost = nums[0] + firstMin + secondMin;
        return minCost;
    }
};