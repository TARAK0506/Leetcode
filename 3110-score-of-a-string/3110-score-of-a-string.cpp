class Solution {
public:
    int scoreOfString(string s) {
      int n=s.size(),score=0;
      for(int i=0;i<n-1;i++){
        score+=abs(int(s[i])-int(s[i+1]));
      }
      return score;
    }
};