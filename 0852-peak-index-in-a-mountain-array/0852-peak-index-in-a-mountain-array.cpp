class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                ans=i;
                break;
            }
        }
        return ans;
    }
};