class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        map<int, vector<int>> mp;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                mp[row + col].push_back(mat[row][col]);
            }
        }

        for (auto& [key, val] : mp) {
            if ((key & 1) == 0) {
                reverse(val.begin(), val.end());
                for (auto& itr : val) {
                    ans.emplace_back(itr);
                }
            } else {
                for (auto& itr : val) {
                    ans.emplace_back(itr);
                }
            }
        }
        return ans;
    }
};