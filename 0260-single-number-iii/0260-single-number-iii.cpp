class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second==2){
                continue;
            }
            else{
                ans.emplace_back(it.first);
            }
        }
        return ans;
    }
};