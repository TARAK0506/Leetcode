class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size()-1;
        double max_sum=INT_MIN;    
        double sum=0,avg=0;
        while(j<=n){
            sum+=nums[j];
            if(j-i+1==k){
                if(max_sum<=sum){
                    max_sum=sum;
                }
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return max_sum/k;
    }
};