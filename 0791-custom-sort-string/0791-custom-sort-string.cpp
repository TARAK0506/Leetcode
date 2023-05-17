class Solution {
public:
    string customSortString(string order,string s) {
        unordered_map<char,int>mp;
        string ans="";
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int j=0;j<order.size();j++){
            if(mp.find(order[j])!=mp.end()){
                // cout<<mp[order[j]]<<" ";
                while(mp[order[j]]>0){
                   ans+=order[j];
                   mp[order[j]]--;
                }
            }
        }
        for(auto it:mp){
            while(it.second>0){
                ans+=it.first;
                it.second--;
            }
        }
        return ans;
    }
};