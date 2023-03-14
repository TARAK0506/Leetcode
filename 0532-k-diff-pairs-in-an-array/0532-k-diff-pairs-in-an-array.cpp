class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        if(k==0)
        {
            for(auto it:mp){
                if(it.second>1)
                {
                    count++;
                }
            }
        }
        else{
        for(auto i:mp)
        {
            if(mp.find(i.first-k)!=mp.end())
            {
               count++;
            }
        }
               }
        return count;
    }
};