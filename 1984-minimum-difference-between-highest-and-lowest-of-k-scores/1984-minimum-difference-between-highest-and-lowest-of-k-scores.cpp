class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minDiff = INT_MAX;
        int i = 0, j = k - 1;
        while (j < n) {
            int minEle = nums[i];
            int maxEle = nums[j];
            minDiff = min(minDiff, maxEle - minEle);
            i++;
            j++;
        }
        return minDiff;
    }
};