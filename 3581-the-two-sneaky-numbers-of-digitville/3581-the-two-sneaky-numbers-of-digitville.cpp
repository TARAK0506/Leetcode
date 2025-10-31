class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> digit(101, 0);
        for (auto& it : nums) {
            digit[it]++;
        }
        vector<int> ans;
        for (int i = 0; i < digit.size(); i++) {
            if (digit[i] == 2)
                ans.emplace_back(i);
        }
        return ans;
    }
};