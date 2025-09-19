class Solution {
public:
    int check(vector<int>& nums, int div) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)(nums[i]) / (double)(div));
        }
        return sum;
    }
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), ans = -1;
        int low = 1, high = findMax(nums);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};