long long maximum(vector<int> &piles){
    int n=piles.size(),maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(maxi<piles[i]){
            maxi=piles[i];
        }
    }
    return maxi;
}
long long minimum(vector<int> &piles,int mid){
    long long n=piles.size(),ans=0;
    for(int i=0;i<n;i++){
        ans+=ceil((double)piles[i]/(double)mid);
    }
    return ans;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maximum(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(minimum(piles,mid)<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};