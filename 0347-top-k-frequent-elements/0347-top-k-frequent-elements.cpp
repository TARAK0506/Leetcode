bool cmp(pair<int,int>p1, pair<int,int>p2)
{
    if(p1.second>p2.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<pair<int,int>>vec;
        for(auto i:nums)
        {
            mp[i]++;
        }
        nums.clear();
        for(auto it:mp)
        {
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<k;i++)
        {
            nums.push_back(vec[i].first);
        }
        return nums;
    }
};