class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        vector<int> ::iterator it;
        for(auto i:nums)
        {
            vector<int>vec;
            while(i!=0)
            {
                vec.push_back(i%10);
                i/=10;
            }
            for(int j=vec.size()-1;j>=0;j--)
            {
                ans.push_back(vec[j]);
            }
        }
        return ans;
    }
};