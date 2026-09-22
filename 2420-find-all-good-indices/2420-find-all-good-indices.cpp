class Solution {
    vector<int> ans;

public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                prefix[i] += prefix[i - 1];
            }
        }
        vector<int> suffix(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] >= nums[i]) {
                suffix[i] += suffix[i + 1];
            }
        }
        for (int i = k; i < n - k; i++) {
            bool increase = false, decrease = false;
            if (i >= 0 && prefix[i - 1] >= k) {
                increase = true;
            }
            if (i + k <= n && suffix[i + 1] >= k) {
                decrease = true;
            }
            if (increase && decrease) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

//          2 1 1 1 3 4 1
// prefix   1 2 3 4 1 1 2
// suffix   1 5 4 3 2 1 1