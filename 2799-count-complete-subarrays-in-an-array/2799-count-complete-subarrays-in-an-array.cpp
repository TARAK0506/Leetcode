class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int k=mp.size(),cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<int>s;
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                if(s.size()==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};