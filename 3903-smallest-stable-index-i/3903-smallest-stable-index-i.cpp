class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), idx = -1;
        vector<int> prefixMax(n, 0);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        vector<int> suffixMin(n, 0);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            int score = prefixMax[i] - suffixMin[i];
            if (score <= k)
                return i;
        }
        return idx;
    }
};