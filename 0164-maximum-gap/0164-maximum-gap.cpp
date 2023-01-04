class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int diff=0;
        int maxDiff=INT_MIN;
        for(int i=1;i<nums.size();i++)
        {
            diff=max(nums[i]-nums[i-1],diff);
            maxDiff=max(maxDiff,diff);
        }
        return maxDiff;
    }
};