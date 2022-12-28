class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        int sol;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1] < nums[i])
            {
                sol=i;
            }
        }
        return sol;
    }
};