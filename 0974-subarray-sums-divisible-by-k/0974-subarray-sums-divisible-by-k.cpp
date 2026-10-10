class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum < 0 ? (sum + k) % k : sum % k;
            rem = rem < 0 ? rem + k : rem;
            if (mp.find(rem) != mp.end())
                cnt += mp[rem];
            mp[rem] += 1;
        }
        return cnt;
    }
};