class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      int maxi=0,ans=0;
      map<int,int>mp;
      for(auto it:nums){
        mp[it]++;
      }
      for(int i=0;i<nums.size();i++){
        maxi=max(maxi,mp[nums[i]]);
      }
      for(int i=0;i<nums.size();i++){
        if(maxi==mp[nums[i]]){
          ans++;
        }
      }
      return ans;
    }
};