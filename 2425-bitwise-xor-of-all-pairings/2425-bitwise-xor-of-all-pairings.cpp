class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(((n1&1)==0) && ((n2&1)==0)){
            return 0;
        }
        else if(((n1&1)!=0) && ((n2&1)!=0)){
            vector<int>nums3=nums1;
            nums3.insert(nums3.end(),nums2.begin(),nums2.end());
            int XOR=0;
            for(auto it:nums3){
                XOR^=it;
            }
            return XOR;
        }
        else if(((n1&1)!=0) && ((n2&1)==0)){
            int XOR=0;
            for(auto it:nums2){
                XOR^=it;
            }
            return XOR;
        }
        else{
            int XOR=0;
            for(auto it:nums1){
                XOR^=it;
            }
            return XOR;
        }
        return 0;
    }
};