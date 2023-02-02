bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
    {
        return a.second>b.second;
    }
     else
    {
        return a.first<b.first;
    }
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        vector<pair<int,int>>vec;
        for(auto i:mp)
        {
            vec.push_back({i.second,i.first});
        }
        nums.clear();
        sort(vec.begin(),vec.end(),cmp);
        for(int it=0;it<vec.size();it++)
        {
             int t=vec[it].first;
             int s=vec[it].second;
             while(t--)
             {  
                 nums.push_back(s);
             }
        }
        return nums;
    }
};