class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      unordered_map<int,int>mp;
      vector<int>ans;
      int n=grid.size()*grid.size();
      n=n*(n+1)/2;
      cout<<n<<" ";
      for(auto& row : grid){
        for(auto& num : row){
            mp[num]++;
        }
      }
      int sum=0;
      for(auto& it:mp){
        sum+=it.first;
        if(it.second==2){
          ans.emplace_back(it.first);
        }
      }
      ans.emplace_back(n-sum);
      return ans;
    }
};