class Solution {
public:
    int check(vector<int>& nums, int mid) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= mid)
                cnt++;
        }
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        int low = 0, high = nums.size();
        while (low <= high) {
            int mid = midpoint(low, high);
            if (check(nums, mid) == mid) {
                return mid;
            } else if (check(nums, mid) > mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};