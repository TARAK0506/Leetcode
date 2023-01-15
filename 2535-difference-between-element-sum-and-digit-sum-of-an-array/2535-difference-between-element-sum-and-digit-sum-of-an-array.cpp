class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int x=0,y=0;
        for(auto i:nums)
        {
            x+=i;
            while(i!=0)
            {
                int r=i%10;
                y+=r;
                i/=10;
            }
        }
        return abs(x-y);
    }
};