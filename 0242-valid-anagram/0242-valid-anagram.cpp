class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:t)
        {
            mp[i]--;
        }
        for(auto it:mp)
        {
              if(it.second!=0)
              {
                  return false;
              }
        }
        return true;
    }
};