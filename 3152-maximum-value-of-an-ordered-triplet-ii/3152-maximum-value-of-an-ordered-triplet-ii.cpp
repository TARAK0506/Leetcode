class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxx = 0;
        int n = nums.size();
        vector<int> prefix_max(n,0), suffix_max(n,0);
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], nums[i - 1]);
        }
        // for (auto& it : prefix_max)
        //     cout << it << " ";
        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i + 1], nums[i + 1]);
        }
        // for (auto& it : suffix_max)
        //     cout << it << " ";
        for (int i = 1; i < n; i++) {
          maxx = max(maxx, (long long)(prefix_max[i] - nums[i]) * suffix_max[i]);
        }
        return maxx;
    }
};