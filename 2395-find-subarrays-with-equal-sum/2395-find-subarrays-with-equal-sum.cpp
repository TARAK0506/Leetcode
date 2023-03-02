class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i;j<nums.size()-1;j++)
            {
                if(i!=j && (nums[i]+nums[i+1]==nums[j]+nums[j+1]))
                {
                    count++;
                }
            }
        }
        if(count)
            return true;
        else
            return false;
    }
};