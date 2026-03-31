class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int m = nums[i].size();
            for (int j = 0; j < m; j++) {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        for (auto& [key, val] : mp) {
            reverse(val.begin(), val.end());
            for (auto& itr : val) {
                ans.emplace_back(itr);
            }
        }
        return ans;
    }
};