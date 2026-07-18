class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = 1001, largest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= smallest) {
                smallest = nums[i];
            }
            if (nums[i] >= largest) {
                largest = nums[i];
            }
        }
        return gcd(smallest, largest);
    }
};