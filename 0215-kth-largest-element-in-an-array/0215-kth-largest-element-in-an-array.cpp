class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        vector<int> ::iterator it=nums.begin()+k-1;
        return *it;
    }
};