class Solution {
public:
    int dfs(vector<int>& nums, int idx, int xorSum) {
        if (idx == nums.size()) {
            return xorSum;
        }
        int pick = dfs(nums, idx + 1, xorSum ^ nums[idx]);
        int notPick = dfs(nums, idx + 1, xorSum);
        return pick + notPick;
    }
    int subsetXORSum(vector<int>& nums) {
        int xorSum = 0;
        return dfs(nums, 0, xorSum);
    }
};