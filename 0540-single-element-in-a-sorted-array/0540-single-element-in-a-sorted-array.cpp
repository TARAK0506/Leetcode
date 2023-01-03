class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        int ans;
        for(auto it:mp)
        {
            if(it.second==1)
            {
                ans=it.first;
            }
        }
        return ans;
    }
};