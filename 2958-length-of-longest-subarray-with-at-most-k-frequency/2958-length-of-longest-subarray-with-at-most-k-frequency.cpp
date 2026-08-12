class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), longest = 0;
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        while (j < n) {
            mpp[nums[j]]++;
            while (mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)
                    mpp.erase(nums[i]);
                i++;
            }
            longest = max(longest, j - i + 1);
            j++;
        }
        return longest;
    }
};