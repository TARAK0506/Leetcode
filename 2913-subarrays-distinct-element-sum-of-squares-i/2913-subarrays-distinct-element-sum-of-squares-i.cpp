class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);
                sum += s.size() * s.size();
            }
            s.clear();
        }
        return sum;
    }
};