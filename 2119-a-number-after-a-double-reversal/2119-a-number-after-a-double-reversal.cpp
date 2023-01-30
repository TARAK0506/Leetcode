class Solution {
public:
    bool isSameAfterReversals(int num) {
        int n=num;
        int s=0,r=0;
        while(n!=0)
        {
            int digit=n%10;
            s=s*10+digit;
            n/=10;
        }
        while(s!=0)
        {
            int digit=s%10;
            r=r*10+digit;
            s/=10;
        }
        if(num==r)
        return true;
        else
            return false;
    }
};