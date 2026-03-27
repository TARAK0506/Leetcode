class Solution {
public:
    int cnt = 0;
    void backtrack(vector<int>& nums, int k, int idx, unordered_map<int, int>& mp) {
        if (idx == nums.size()) {
            if (!mp.empty())
                cnt++;
            return;
        }

        backtrack(nums, k, idx + 1, mp);
        if (mp[nums[idx] - k] == 0) {
            mp[nums[idx]]++;
            backtrack(nums, k, idx + 1, mp);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        unordered_map<int, int> mp;
        backtrack(nums, k, 0, mp);
        return cnt;
    }
};