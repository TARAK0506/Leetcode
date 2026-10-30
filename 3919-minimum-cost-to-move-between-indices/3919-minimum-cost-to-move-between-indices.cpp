class Solution {
    int n, q;

public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size(), q = queries.size();
        vector<int> closest(n, 0);
        closest[0] = 1, closest[n - 1] = n - 2;
        for (int i = 1; i < n - 1; i++) {
            closest[i] = abs(nums[i] - nums[i + 1]) < abs(nums[i] - nums[i - 1])
                             ? i + 1
                             : i - 1;
        }
        vector<int> prefixCost(n + 1, 0);
        for (int i = 1; i < n; i++) {
            prefixCost[i] =
                prefixCost[i - 1] +
                (closest[i - 1] == i ? 1 : abs(nums[i] - nums[i - 1]));
        }
        vector<int> suffixCost(n + 1, 0);
        for (int i = n - 2; i >= 0; i--) {
            suffixCost[i] =
                suffixCost[i + 1] +
                (closest[i + 1] == i ? 1 : abs(nums[i + 1] - nums[i]));
        }
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = (l <= r ? prefixCost[r] - prefixCost[l]
                             : suffixCost[r] - suffixCost[l]);
        }
        return ans;
    }
};