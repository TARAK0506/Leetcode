class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x) {
            int rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int rev = reverse(nums[i]);
            if (mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }
            mp[rev] = i;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};