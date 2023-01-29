class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp,mp1;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto j:t)
        {
            mp[j]--;
        }
        int count=0;
        for(auto it:mp)
        {
           if(it.second <= -1)
           {
               count+=it.second;
           }
        }
        return abs(count);
        return 0;
    }
};