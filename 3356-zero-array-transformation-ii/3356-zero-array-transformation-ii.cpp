class Solution {
    int n, q, ans;

public:
    bool all_Zeros(vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                return false;
        }
        return true;
    }
    bool check(vector<vector<int>>& queries, vector<int>& nums, int k) {
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            diff[r + 1] -= val;
        }
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diff[i];
            if (nums[i] - curr > 0)
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size(), q = queries.size(), ans = -1;
        if (all_Zeros(nums))
            return 0;
        int low = 1, high = q;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(queries, nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};