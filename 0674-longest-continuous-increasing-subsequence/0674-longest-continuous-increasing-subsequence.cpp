class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 1;
        }
        int count=1;
        int maxi=1;
        for(int i=0;i<nums.size()-1;i++)
        {
           if(nums[i]<nums[i+1])
           {
               count++;
               maxi=max(count,maxi);
           }
           else
           {
              count=1;
           }
        }
        return maxi;
    }
};