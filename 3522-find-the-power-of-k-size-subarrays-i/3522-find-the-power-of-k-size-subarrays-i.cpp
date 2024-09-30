class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
      vector<int>ans;
      int maxi = INT_MIN;
        for(int i=0;i<=nums.size()-k;i++){
          int flag=1;
          for(int j=i;j<i+k-1;j++){
            if(nums[j] != nums[j + 1]-1){
                  flag=0;
                  break;
              }
          }
          if(flag) ans.emplace_back(nums[i+k-1]);
          else ans.emplace_back(-1);
        }
      return ans;
    }
};