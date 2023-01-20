class Solution {
public:
    bool isHappy(int n) {
        int square_sum=0,digit;
        if(n<=4)
        {
            if(n==1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        while(n!=0)
        {
            digit=n%10;
            square_sum+=digit*digit;
            n/=10;
        }
        return isHappy(square_sum);
    }
};