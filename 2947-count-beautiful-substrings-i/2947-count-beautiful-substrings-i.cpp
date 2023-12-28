bool isvowel(char ch){
  if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
  else return false;
}
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
          int v_cnt=0,c_cnt=0;
          for(int j=i;j<s.size();j++){
            if(isvowel(s[j])) v_cnt++;
            else c_cnt++;
            if(v_cnt==c_cnt && (v_cnt* c_cnt)%k==0)
              ans++;
          }
        }
      return ans;
    }
};