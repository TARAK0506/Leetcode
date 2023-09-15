class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector< vector<string> >ans;
      unordered_map<string,vector<string>>mp;
      for(int i=0;i<strs.size();i++){
        string str=strs[i];
        sort(str.begin(),str.end());
        mp[str].push_back(strs[i]);
      }
      for(auto itr:mp){
        ans.emplace_back(itr.second);
      }
      return ans;
    }
};