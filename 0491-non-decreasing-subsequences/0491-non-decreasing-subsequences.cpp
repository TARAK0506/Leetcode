class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int idx, vector<int>& nums, vector<int>& ds) {
        if (ds.size() >= 2) {
            ans.emplace_back(ds);
        }
        if (idx >= nums.size())
            return;
        unordered_set<int> st;
        for (int i = idx; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) continue;
            if (ds.empty() || ds.back() <= nums[i]) {
                ds.emplace_back(nums[i]);
                st.insert(nums[i]);
                dfs(i + 1, nums, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ds;
        dfs(0, nums, ds);
        return ans;
    }
};