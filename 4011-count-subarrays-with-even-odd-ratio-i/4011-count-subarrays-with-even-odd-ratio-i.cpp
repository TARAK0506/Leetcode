class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;
            for (int j = i; j < n; j++) {
                if ((nums[j] & 1))
                    y++;
                else
                    x++;
                if (y == 0)
                    continue;
                if (((double)x / (double)y) <= (double(a / (double)b)))
                    ans++;
            }
        }
        return ans;
    }
};