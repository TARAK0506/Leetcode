class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<=nums.size();i++)
        {
            mp[i]=0;
        }
        for(auto j=0;j<nums.size();j++)
        {
            mp[nums[j]]++;
        }
        int ans;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(i->second==0)
            {
                ans=i->first;
            }
        }
        return ans;
    }
};