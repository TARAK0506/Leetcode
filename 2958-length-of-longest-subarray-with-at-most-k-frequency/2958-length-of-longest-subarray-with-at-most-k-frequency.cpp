class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      int i=0,j=0,n=nums.size(),maxi=INT_MIN;
      while(j<n){
        mp[nums[j]]++;
        while(mp[nums[j]]>k){
          mp[nums[i]]--;
          if(mp[nums[i]]==0){
            mp.erase(nums[i]);
          }
          i++;
        }
        maxi=max(maxi,j-i+1);
        j++;
      }
      return maxi;
    }
};