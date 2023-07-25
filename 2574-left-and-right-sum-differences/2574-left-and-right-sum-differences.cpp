class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>leftsum,rightsum;
        for(int i=0;i<nums.size();i++){
            int left_sum=0;
            for(int j=0;j<=i-1;j++){
                left_sum+=nums[j];
            }
            leftsum.emplace_back(left_sum);
        }
        for(int i=0;i<nums.size();i++){
            int right_sum=0;
            for(int j=i+1;j<=nums.size()-1;j++){
                right_sum+=nums[j];
            }
            rightsum.emplace_back(right_sum);
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.emplace_back(abs(leftsum[i]-rightsum[i]));
        }
        return ans;
    }
};