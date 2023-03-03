class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int ans=INT_MIN;
        stack<int>s;
        s.push(nums[0]);
        int sum=nums[0],maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>s.top())
            {
                sum+=nums[i];
                s.push(nums[i]);
            }
            else
            {
                ans=max(ans,sum);
                sum=0;
                while(!s.empty())
                {
                    s.pop();
                }
                s.push(nums[i]);
                sum=nums[i];
            }
        }
         ans=max(ans,sum);
        return ans;
    }
};