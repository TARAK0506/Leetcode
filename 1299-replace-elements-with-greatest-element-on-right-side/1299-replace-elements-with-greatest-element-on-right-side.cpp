class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
      vector<int>ans;
      ans.emplace_back(-1);
      int maxi=-1;
      for(int i=arr.size()-1;i>0;i--){
        if(arr[i]>=maxi){
          maxi=max(maxi,arr[i]);
        }
        ans.emplace_back(maxi);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};