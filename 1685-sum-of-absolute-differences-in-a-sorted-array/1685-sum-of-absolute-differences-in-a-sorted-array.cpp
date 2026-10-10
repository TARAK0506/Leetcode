class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];

        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            int s1 = i * nums[i] - (prefix[i] - prefix[0]);
            int s2 = (prefix[n] - prefix[i + 1]) - ((n - i - 1) * nums[i]);
            result[i] = s1 + s2;
        }
        return result;
    }
};