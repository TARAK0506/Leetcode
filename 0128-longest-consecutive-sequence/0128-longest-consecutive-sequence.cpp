class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int lastsmaller = INT_MIN,n=nums.size(),cnt=0,longest=1;
      if(nums.size()==0) return 0;
      sort(nums.begin(),nums.end());
      for(int i=0;i<n;i++){
        if(nums[i]-1 == lastsmaller){
          cnt++;
          lastsmaller = nums[i];
        }
        else if(nums[i]!=lastsmaller){
          cnt=1;
          lastsmaller = nums[i];
        }
        longest = max(longest,cnt);
      }
      return longest;
    }
};