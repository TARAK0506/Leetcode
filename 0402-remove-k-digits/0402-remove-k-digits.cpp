class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char ch:num){
          while(!st.empty() && st.top()>ch && k>0){
            st.pop();
            k--;
          }
          st.push(ch);
        }
        while(k>0 && !st.empty()){
          st.pop();
          k--;
        }
        string ans="";
        while(!st.empty()){
          ans+=st.top();
          st.pop();
        }
        reverse(ans.begin(),ans.end());
        int cnt = 0;
        while(cnt<ans.size() && ans[cnt]=='0') {
            cnt++;
        }
        ans =(cnt==ans.size())?"0":ans.substr(cnt);
        return ans;
    }
};