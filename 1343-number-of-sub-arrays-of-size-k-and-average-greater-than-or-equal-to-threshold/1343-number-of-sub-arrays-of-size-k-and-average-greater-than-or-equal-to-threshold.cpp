class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0,size=0,count=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            size++;
            if(size==k){
                if((sum)/k >= threshold){
                    count++;
                }
                sum-=arr[i-k+1];
                size--;
            }
        }
        return count;
    }
};