class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0,n=s.size(),window_size=p.length();
        unordered_map<char,int>mp,mp1;
        vector<int>ans;
        for(auto it:p){
            mp[it]++;
        }
        while(j<n){
            mp1[s[j]]++;
             if (j-i+1==window_size){
                unordered_map<char, int> map(mp);
                bool isAnagram=true;
                for(auto it:mp1) {
                    if (map.find(it.first)==map.end() || map[it.first]!=it.second){
                        isAnagram=false;
                        break;
                    }
                }
                if(isAnagram){
                    ans.emplace_back(i);
                }
                mp1[s[i]]--;
                if(mp1[s[i]]==0){
                    mp1.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};