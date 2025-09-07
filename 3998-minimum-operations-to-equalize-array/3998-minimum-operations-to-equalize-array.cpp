class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s;
        for (auto& num : nums) {
            s.insert(num);
        }
        return (s.size() == 1) ? 0 : 1;
    }
};