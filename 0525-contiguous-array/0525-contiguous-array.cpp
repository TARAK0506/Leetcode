class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }
        }
        int maxi=0,sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==0)
            {
                maxi=max(maxi,i+1);
            }
            if(mp.find(sum)!=mp.end())
            {
                maxi=max(maxi,i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        return maxi;
    }
};