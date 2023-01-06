class Solution {
public:
    int countEven(int num) {
        int count=0;
        for(int i=1;i<=num;i++)
        {
            int n=i;
            int sum=0;
            while(n!=0)
            {
                int r=n%10;
                n/=10;
                sum+=r;
            }
            if(sum%2==0)
            {
                count++;
            }
        }
        return count;
    }
};