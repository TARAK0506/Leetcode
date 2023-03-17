class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int sum=0,count=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                count++;
                if(count%2!=0)
                {
                    ans+=sum;
                }
            }
        }
        return ans;
    }
};