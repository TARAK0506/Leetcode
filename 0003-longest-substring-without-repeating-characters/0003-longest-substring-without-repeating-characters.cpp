class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0,n=s.size(),maxi=0;
        for(int j=0;j<n;j++){
            if(mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }
            mp[s[j]]=j;
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};