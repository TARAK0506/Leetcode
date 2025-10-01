class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArray(n + 1, 0);
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            diffArray[l] += 1;
            diffArray[r + 1] -= 1;
        }
        for (int i = 1; i < n; i++) {
            diffArray[i] += diffArray[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (diffArray[i] < nums[i])
                return false;
        }

        return true;
    }
};