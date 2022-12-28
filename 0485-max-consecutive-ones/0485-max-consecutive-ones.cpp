class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                count++;
            }
            else
            {
                if(maxi<count)
                {
                    maxi=count;
                }
                count=0;
            }
        }
        if(count>maxi)
        {
            return count;
        }
        return maxi;
    }
};