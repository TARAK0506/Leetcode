class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])<=abs(mini))
            {
                mini=nums[i];
            }
        }
        return mini;
    }
};