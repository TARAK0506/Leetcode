class Solution {
public:
    int beautySum(string s) {
        int maxi,mini,ans=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                mp[s[j]]++;
                maxi=INT_MIN,mini=INT_MAX;
                for(auto it:mp)
                {
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                ans+=maxi-mini;
            }
            mp.clear();
        }
        return ans;
    }
};