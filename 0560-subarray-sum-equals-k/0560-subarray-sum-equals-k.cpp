class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end())
                cnt += mp[sum - k];
            mp[sum]++;
        }
        return cnt;
    }
};