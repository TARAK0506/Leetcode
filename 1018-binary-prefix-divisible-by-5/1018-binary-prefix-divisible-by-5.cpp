class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), xi = 0;
        vector<bool> answer;
        for (int i = 0; i < n; i++) {
            xi = (xi * 2 + nums[i]) % 5;
            answer.emplace_back(xi == 0);
        }
        return answer;
    }
};