class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=nums.size()/2;
        int sum=0;
        for(int i=0;i<2*j-1;i=i+2)
        {
            sum+=min(nums[i],nums[i+1]);
        }
    return sum;
    }
};