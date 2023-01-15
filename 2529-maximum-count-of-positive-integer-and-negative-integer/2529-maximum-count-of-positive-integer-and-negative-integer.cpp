class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=0,pos=0,count=0;
        for(auto i:nums)
        {
            if(i<0)
            {
                neg++;
            }
            else if(i>0)
            {
                pos++;
            }
            else
            {
                count++;
            }
        }
        if(neg>pos)
        {
            return neg;
        }
        return pos;
    }
};