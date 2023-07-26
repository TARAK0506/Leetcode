string decimalToBinary(int decimal,int base) {
    string result = "";
    while (decimal>0){
        int remainder=decimal%base;
        result=to_string(remainder)+result;
        decimal/=base;
    }
    return result;
}
int ispalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int b=2;b<=n-2;b++){
           string str=decimalToBinary(n,b);
           if(!ispalindrome(str)){
               return false;
           }
        }
        return true;
    }
};