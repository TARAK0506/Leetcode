class Solution {
public:
    unordered_map<int, int> mp;
    void dfs(int idx, int bitwise_or, vector<int>& nums) {
        if (idx == nums.size()) {
            mp[bitwise_or]++;
            return;
        }
        dfs(idx + 1, (bitwise_or | nums[idx]), nums);
        dfs(idx + 1, bitwise_or, nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        dfs(0, 0, nums);
        int maxOr = 0;
        for (auto& [key, val] : mp) {
            maxOr = max(maxOr, key);
        }
        return mp[maxOr];
    }
};