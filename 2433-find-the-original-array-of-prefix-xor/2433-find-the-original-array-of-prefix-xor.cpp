class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
       vector<int>ans;
       ans.emplace_back(pref[0]);
       for(int i=1;i<pref.size();i++){
           int temp=pref[i-1]^pref[i];
           ans.emplace_back(temp);
       }
        return ans;
    }
};