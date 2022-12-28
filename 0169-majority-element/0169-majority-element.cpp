class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size()/2;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int r;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(i->second > n)
            {
                r=i->first;
            }
        }
        return r;
    }
};