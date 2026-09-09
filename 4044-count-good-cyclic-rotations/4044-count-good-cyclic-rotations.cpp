using ll = long long;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        ll n = nums.size(), cnt = 0;
        ll idx = 0, len = n / 2;
        ll sum1 = 0, sum2 = 0;
        while (idx < len) {
            sum1 += nums[idx];
            sum2 += nums[len + idx];
            idx++;
        }
        idx = 0;
        while (idx < n) {
            if (sum1 > sum2)
                cnt++;
            sum1 = sum1 - nums[idx] + nums[(len + idx) % n];
            sum2 = sum2 + nums[idx] - nums[(len + idx) % n];
            idx++;
        }
        return cnt;
    }
};