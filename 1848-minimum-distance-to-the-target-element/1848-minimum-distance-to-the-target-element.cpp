class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size(), minDist = 1e4;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                minDist = min(minDist, abs(i - start));
            }
        }
        return minDist;
    }
};