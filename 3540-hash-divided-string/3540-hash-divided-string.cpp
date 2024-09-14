class Solution {
public:
    
    string stringHash(string s, int k) {
        map<char,int>mp;
        int i=0,n=s.length();
        for(char ch = 'a';ch<='z';ch++){
          mp[ch] = i;
          i++;
        }
        int length = n / k;
        string result = "";
        for (int i = 0; i < n; i += k) {
            string str = s.substr(i, k);
            int sum = 0;
            for (int j = 0; j < str.size(); j++) {
                sum += mp[str[j]];
            }
            char ch = 'a'+(sum)%26;
            result += ch;
        }
        return result;
    }
};