class Solution {
public:
    int maxScore(vector<int>& nums) {
        int ans=0;
        sort(nums.rbegin(),nums.rend());
        vector<long long>prefixsum(nums.size());
        prefixsum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        for(auto it:prefixsum){
           if(it>0){
               ans++;
           }
        }
        return ans;
    }
};