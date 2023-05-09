class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0,n=gain.size();
        vector<int>prefixsum;
        prefixsum.push_back(0);
        for(auto it:gain){
            sum+=it;
            prefixsum.emplace_back(sum);
        }
        sort(prefixsum.rbegin(),prefixsum.rend());
        return prefixsum[0];
    }
};