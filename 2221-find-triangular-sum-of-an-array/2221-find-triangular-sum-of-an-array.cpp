class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        while(nums.size()!=1){
        for(int i=0;i+1<nums.size();i++){
            int n=(nums[i]+nums[i+1])%10;
            nums[i]=n;
        }
        nums.erase(nums.end()-1);
        // for(auto it:nums){
        //     cout<<it<<" ";
        // }
        //     cout<<endl;
        }
        return nums[0];
    }
};