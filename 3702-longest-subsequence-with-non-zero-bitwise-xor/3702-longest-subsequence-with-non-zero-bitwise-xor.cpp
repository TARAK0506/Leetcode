class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(), XOR = 0;
        bool allZeros = true;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                allZeros = false;
            }
            XOR ^= nums[i];
        }
        if(allZeros) return 0;
        return (XOR == 0) ? n - 1 : n;
    }
};