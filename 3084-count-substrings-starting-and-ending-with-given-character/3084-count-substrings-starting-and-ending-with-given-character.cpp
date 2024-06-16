class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt=0,i=0,j=s.length();
        while(i<=j){
           if(s[i]==c){
               cnt++;
           } 
            i++;
        }
        return cnt*(cnt+1)/2;
    }
};