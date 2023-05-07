class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' ||ch=='i' || ch=='o' ||ch=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    int maxVowels(string s, int k) {
       int i=0,n=s.size(),count=0,maxi=INT_MIN,size=0;
        for(int j = 0; j<n; j++){
            if(isvowel(s[j])) count++;
            if(j-i+1 == k){
                maxi = max(maxi, count);
                if(isvowel(s[i])) count--;
                i++;
            } 
        }
     return maxi;
    }
};