class Solution {
public:
    bool isPalindrome(int x) {
      long rev=0,num=x;
      if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
      }
      while(x){
        rev=rev*10+x%10;
        x=x/10;
      }
      if(rev==num){
        return true;
      }
      return false;
    }
};