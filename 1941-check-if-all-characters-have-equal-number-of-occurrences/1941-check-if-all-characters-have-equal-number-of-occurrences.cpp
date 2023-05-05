class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        unordered_map<int,int>mp2;
        for(auto it:s){
            mp[it]++;
        }
        for(auto itr:mp){
            mp2[itr.second]++;
        }
        if(mp2.size()==1){
            return true;
        }
        else{
            return false;
        }
    }
};