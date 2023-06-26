int maximum(vector<int> &weights){
    int maxi=INT_MIN;
    for(int i=0;i<weights.size();i++){
        if(maxi<weights[i]){
            maxi=weights[i];
        }
    }
    return maxi;
}
int totalsum(vector<int> &weights){
    int sum=0;
    for(auto it:weights){
        sum+=it;
    }
    return sum;
}
int noofdays(vector<int> &weights,int mid){
    int day=1,load=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+load>mid){
            day+=1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return day;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=maximum(weights),high=totalsum(weights);
        while(low<=high){
            int mid=(low+high)/2;
            if(noofdays(weights,mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};