class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int p) {
        int n = nums.size(), cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= mid) {
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[n - 1] - nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};