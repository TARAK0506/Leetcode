class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> vec;
        map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        for(auto it:mp)
        {
            if(it.second==1 && !mp.count(it.first+1) && !mp.count(it.first-1))
            {
                vec.push_back(it.first);
            }
        }
        return vec;
    }
};