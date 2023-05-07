class Solution {
public:
    bool isvowel(char ch){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||  ch=='A' || ch=='E' || ch=='I' || ch=='O' ||ch=='U' ){
                return true;
            }
            else{
                return false;
            }
        }
    bool halvesAreAlike(string s) {
        int count=0,count1=0;
        for(int i=0;i<s.length()/2;i++){
            if(isvowel(s[i])){
                count++;
            }
        }
        for(int i=s.length()/2;i<s.length();i++){
            if(isvowel(s[i])){
                count1++;
            }
        }
        if(count==count1){
            return true;
        }
        else{
            return false;
        }
    }
};