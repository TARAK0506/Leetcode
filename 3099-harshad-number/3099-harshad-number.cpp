class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
      int sum=0,n=x;
        while(n>0){
          int num=n%10;
          sum+=num;
          n=n/10;
        }
      if(x % sum ==0){
        return sum;
      }
      else{
        return -1;
      }
      return 0;
    }
};