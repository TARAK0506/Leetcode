class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int XOR=0;
        for(auto it:nums){
            XOR^=it;
        }
        return XOR;
    }
};