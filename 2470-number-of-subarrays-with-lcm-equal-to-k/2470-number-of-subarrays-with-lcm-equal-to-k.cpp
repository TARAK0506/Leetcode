int LCM(int a,int b){
    int ans=(a*b)/__gcd(a,b);
    return ans;
}
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int lcm1=nums[i];
            for(int j=i;j<nums.size();j++){
                lcm1=LCM(lcm1,nums[j]);
                if(lcm1==k){
                    count++;
                }
                if(lcm1>k){
                    break;
                }
            }
        }
        return count;
    }
};