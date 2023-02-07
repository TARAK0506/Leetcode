class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>vec;
        int f=1;
        for(int i=left;i<=right;i++)
        {
            int n=i,num=i,f=1;
            while(n!=0)
            {
                int val=n%10;
                if(val==0)
                {
                    f=0;
                    break;
                }
                if(num%val!=0)
                {
                    f=0;
                }
                n/=10;
            }
            if(f==1)
            {
                vec.push_back(i);
            }
        }
        return vec;
    }
};