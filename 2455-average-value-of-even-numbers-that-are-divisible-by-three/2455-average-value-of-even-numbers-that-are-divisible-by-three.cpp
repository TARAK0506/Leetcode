class Solution {
public:
    int averageValue(vector<int>& nums) {
        vector<int> vec;
        for(auto i:nums)
        {
            if(i%6==0)
            {
                vec.push_back(i);
            }
        }
        int sum=0;
        int n=vec.size();
        for(auto it:vec)
        {
            sum+=it;
        }
        if(n==0)
        {
            return 0;
        }
        else
        {
            return round(sum/n);
        }
    }
};