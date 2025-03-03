class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt = 0;
        vector<int> smaller, larger;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot)
                smaller.emplace_back(nums[i]);
            else if (nums[i] == pivot) {
                cnt++;
            } else
                larger.emplace_back(nums[i]);
        }
        nums.clear();
        for (auto it : smaller) {
            nums.emplace_back(it);
        }
        while (cnt--) {
            nums.emplace_back(pivot);
        }
        for (auto it : larger) {
            nums.emplace_back(it);
        }
        return nums;
    }
};