class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int col = 0; col < nums[0].size(); col++) {
            int maxi = 0;
            for (int row = 0; row < nums.size(); row++) {
                maxi = max(maxi, nums[row][col]);
            }
            ans += maxi;
        }
        return ans;
    }
};