class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp,mp1;
        for(auto it:words1)
        {
            mp[it]++;
        }
        for(auto i:words2)
        {
            mp1[i]++;
        }
        int count=0;
        for(auto itr:mp)
        {
           if(mp1[itr.first]==1 && itr.second==1)
           {
               count++;
           }
        }
        return count;
    }
};