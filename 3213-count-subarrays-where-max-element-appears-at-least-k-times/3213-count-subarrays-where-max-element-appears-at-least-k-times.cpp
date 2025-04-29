class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int i = 0, j = 0, n = nums.size();
        long long cnt = 0;
        unordered_map<int, int> mp;
        while (j < n) {
            if (nums[j] == maxi)
                mp[nums[j]]++;
            while (mp[nums[j]] >= k) {
                cnt += (n - j);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};