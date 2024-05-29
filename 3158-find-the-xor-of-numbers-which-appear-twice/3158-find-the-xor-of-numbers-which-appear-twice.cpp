class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
      unordered_map<int,int>mp;
      int ans=0;
      for(auto it:nums){
        mp[it]++;
      }
      for(auto it:mp){
        if(it.second==2){
          ans^=it.first;
        }
      }
      return ans;
    }
};