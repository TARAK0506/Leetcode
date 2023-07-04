int firstdigit(int n){
    while(n>9){
        n=n/10;
    }
    return n;
}
int lastdigit(int n){
    n=n%10;
    return n;
}
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(__gcd(firstdigit(nums[i]),lastdigit(nums[j]))==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};