class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int f=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(-nums[i])!=mp.end())
            {
                maxi=max(maxi,nums[i]);
                f=1;
            }
        }
        if(f==1)
            return maxi;
        else
            return -1;
    }
};