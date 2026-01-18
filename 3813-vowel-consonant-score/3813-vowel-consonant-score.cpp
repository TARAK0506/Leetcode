class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int vowelConsonantScore(string s) {
        int n = s.length();
        int vowelCnt = 0, consonantCnt = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i]))
                vowelCnt++;
            else if (isdigit(s[i]) || s[i] == ' ')
                continue;
            else
                consonantCnt++;
        }
        return (consonantCnt == 0 ? 0 : floor(vowelCnt / consonantCnt));
    }
};