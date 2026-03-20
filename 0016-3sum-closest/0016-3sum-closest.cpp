class Solution {
public:
    int closestSum = 1e6;
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int i = 0, n = nums.size();
        if (n < 3)
            return {};
        while (i < n - 2) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
            i++;
        }
        return closestSum;
    }
};