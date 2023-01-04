class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(sum>9 || num>0)
        {
            if(num==0)
            {
                num=sum;
                sum=0;
            }
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
};