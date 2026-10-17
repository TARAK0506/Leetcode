class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size(), cnt = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum - target) != mp.end()) {
                cnt += 1;
                sum = 0;
                mp.clear();
            }
            mp[sum] += 1;
        }
        return cnt;
    }
};