class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
      int max=*max_element(nums.begin(),nums.end());
      long long i=0,j=0,n=nums.size(),ans=0,freq=0;
      while(j<n){ 
        if(nums[j]==max){
          freq++;
        }
        while(freq==k){
          if(nums[i]==max){
            freq--;
          }
          i++;
        }
        j++;
        ans+=i;
      }
      return ans;
    }
};