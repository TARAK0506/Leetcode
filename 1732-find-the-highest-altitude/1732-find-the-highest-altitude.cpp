class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>prefix(gain.size());
        prefix[0]=gain[0];
        for(int i=1;i<gain.size();i++){
            prefix[i]=gain[i]+prefix[i-1];
        }
        prefix.emplace_back(0);
        sort(prefix.rbegin(),prefix.rend());
        return prefix[0];
    }
};