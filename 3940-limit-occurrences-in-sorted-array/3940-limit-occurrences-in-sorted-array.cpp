class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] <= k) {
                arr.emplace_back(nums[i]);
            }
        }
        return arr;
    }
};