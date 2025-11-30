class Solution {
public:
    int upperBound(vector<int>& nums, int target, int idx) {
        int n = nums.size();
        int low = idx, high = n - 1, ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }

    int countElements(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int idx = upperBound(nums, nums[i], i);
            if (n - idx >= k)
                ans++;
        }
        return ans;
    }
};