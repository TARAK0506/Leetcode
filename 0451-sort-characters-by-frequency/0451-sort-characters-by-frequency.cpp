class Solution {
public:
    string frequencySort(string s) {
       map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        vector<pair<int,char>> vec;
        for(auto it:mp)
        {
            vec.push_back({it.second,it.first});
        }
        sort(vec.rbegin(),vec.rend());
        string ans = "";
         for(int i=0;i<vec.size();i++)
         {
             int t=vec[i].first;
             while(t--)
             {
                 ans+=vec[i].second;
             }
        }
        return ans;
    }
};