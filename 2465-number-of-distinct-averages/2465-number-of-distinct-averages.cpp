class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_map<float,int>mp;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<=j){
            float avg=(float)(nums[i]+nums[j])/2;
            // cout<<avg<<" "<<endl;
            mp[avg]++;
            i++;j--;
        }
        return mp.size();
    }
};