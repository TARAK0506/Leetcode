class Solution {
public:
    int countDigits(int num) {
        int val;
        int count=0;
        int n=num;
       while(num!=0)
       {
           val=num%10;
           if(n%val==0)
           {
               count++;
           }
           num/=10;
       }
        return count;
    }
};