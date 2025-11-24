class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), xi = 0;
        vector<bool> answer(n);
        for (int i = 0; i < n; i++) {
            xi = (xi * 2 + nums[i]) % 5;
            answer[i] = (xi == 0);
        }
        return answer;
    }
};