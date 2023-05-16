class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int rem=nums[i]%60;
            if(rem==0){
                ans+=mp[0];
            }
            else if(mp.find(60-rem)!=mp.end()){
                ans+=mp[60-rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};