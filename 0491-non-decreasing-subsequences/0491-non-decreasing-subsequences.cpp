class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int idx, vector<int>& nums, vector<int>& ds) {
        if (idx == nums.size()) {
            if (ds.size() >= 2) {
                ans.push_back(ds);
            }
            return;
        }
        if (ds.empty() || ds.back() <= nums[idx]) {
            ds.push_back(nums[idx]);
            dfs(idx + 1, nums, ds);
            ds.pop_back();
        }
        if (ds.empty() || ds.back() != nums[idx]) {
            dfs(idx + 1, nums, ds);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ds;
        dfs(0, nums, ds);
        return ans;
    }
};