class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size(),mini=INT_MAX,sum=0,flag=0;
        while(i<n){
            sum+=nums[i];
            if(sum<target){
                i++;
                flag=0;
            } 
            else{
                while(sum>=target){
                    mini=min(mini,i-j+1);
                    sum-=nums[j];
                    j++;
                }
                flag=1;
                i++;
            }
        }
        if(mini==INT_MAX){
            return 0;
        }
        else{
            return mini;
        }
    }
};