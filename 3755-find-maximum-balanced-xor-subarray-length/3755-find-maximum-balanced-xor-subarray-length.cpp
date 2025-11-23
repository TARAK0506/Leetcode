class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size(), maxLen = 0;
        int prefixXor = 0, prefixDiff = 0;
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        for (int i = 0; i < n; i++) {
            prefixXor ^= nums[i];
            prefixDiff += (nums[i] & 1 ? -1 : 1);
            if (mp.find({prefixXor, prefixDiff}) != mp.end()) {
                maxLen = max(maxLen, i - mp[{prefixXor, prefixDiff}]);
            } else
                mp[{prefixXor, prefixDiff}] = i;
        }
        return maxLen;
    }
};