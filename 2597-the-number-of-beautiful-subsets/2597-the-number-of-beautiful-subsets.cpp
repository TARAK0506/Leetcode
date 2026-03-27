class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;
    void backtrack(vector<int>& nums, int k, int idx, vector<int>& ds,
                   unordered_map<int, int>& mp) {
        if (idx == nums.size()) {
            if (!ds.empty())
                ans.emplace_back(ds);
            return;
        }

        backtrack(nums, k, idx + 1, ds, mp);
        if (mp[nums[idx] - k] == 0) {
            mp[nums[idx]]++;
            ds.emplace_back(nums[idx]);
            backtrack(nums, k, idx + 1, ds, mp);
            mp[nums[idx]]--;
            ds.pop_back();
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        unordered_map<int, int> mp;
        backtrack(nums, k, 0, ds, mp);
        return ans.size();
    }
};