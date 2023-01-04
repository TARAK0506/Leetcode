class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mp,mp1;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:t)
        {
            mp[i]--;
        }
        char ans;
        for(auto it:mp)
        {
            if(it.second <0)
            {
                ans=it.first;
            }
        }
        return ans;
    }
};