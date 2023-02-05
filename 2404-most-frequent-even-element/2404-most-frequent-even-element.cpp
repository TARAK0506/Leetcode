bool cmp(pair<int,int>p1, pair<int,int> p2)
{
    if(p1.first==p2.first)
    {
        return p1.second>p2.second;
    }
    else
    {
        return p1.first<p2.first;
    }
}
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        vector<pair<int,int>> vec;
        for(auto i:nums)
        {
            if(i%2==0)
             mp[i]++;
        }
        for(auto it:mp)
        {
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end(),cmp);
        reverse(vec.begin(),vec.end());
        // for(auto it:vec)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        //}
        for(auto it:vec)
        {
            return it.second;
            break;
        }
        return -1;
    }
};