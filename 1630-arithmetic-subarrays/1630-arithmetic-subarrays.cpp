bool isArithmetic(vector<int>& vec)
{
    if(vec.size()==2)
    {
        return true;
    }
    int diff=vec[1]-vec[0];
    for(int i=2;i<vec.size();i++)
    {
        if(vec[i]-vec[i-1]!=diff)
        {
            return false;
        }
    }
    return true;
}
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++)
        {
            vector<int>vec;
            int a=l[i],b=r[i];
            for(int j=a;j<=b;j++)
            {
                vec.push_back(nums[j]);
            }
            sort(vec.begin(),vec.end());
            if(isArithmetic(vec))
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};