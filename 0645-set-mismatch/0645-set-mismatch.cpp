class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        vector<int> vec;
        for(auto i=1;i<=nums.size();i++)
        {
            mp[i]=0;
        }
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second == 2)
            {
                vec.insert(vec.begin(),it->first);
            }
            if(it->second == 0)
            {
                vec.push_back(it->first);
            }
        }
        return vec;
    }
};