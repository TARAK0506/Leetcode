class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      long long left=0,right=0,product=1,n=nums.size(),ans=0;
      while(right<n){
        product*=nums[right];
        while(left<=right && product>=k){
          product/=nums[left];
          left++;
        }
        ans+=right-left+1;
        right++;
      }
      return ans;
    }
};