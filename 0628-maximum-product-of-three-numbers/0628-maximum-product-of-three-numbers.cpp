class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int p=nums[n-1]*nums[n-2]*nums[n-3];
        int p1=nums[0]*nums[1]*nums[n-1];
        int maxi=max(p1,p);
        return maxi;
    }
};