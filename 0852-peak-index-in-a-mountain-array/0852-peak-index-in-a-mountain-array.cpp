class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=1,high=arr.size()-2,ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
                break;
            }
            else if(arr[mid]>arr[mid-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};