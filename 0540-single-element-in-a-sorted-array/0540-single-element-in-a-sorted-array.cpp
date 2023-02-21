class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        for(auto it:mp)
        {
            if(it.second==1)
            {
                ans= it.first;
            }
        }
        return ans;
    }
};