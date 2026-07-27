#define all(x) sort(begin(x), end(x))
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        all(nums);
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};