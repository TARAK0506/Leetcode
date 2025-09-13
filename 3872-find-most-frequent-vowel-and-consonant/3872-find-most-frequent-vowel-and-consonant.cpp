class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }
    int maxFreqSum(string s) {
        vector<int> letters(26, 0);
        for (int i = 0; i < s.length(); i++) {
            letters[s[i] - 'a']++;
        }
        int vowelMaxFreq = 0, consonantMaxFreq = 0;
        for (int i = 0; i < letters.size(); i++) {
            char ch = 'a' + i;
            if (isVowel(ch)) {
                vowelMaxFreq = max(vowelMaxFreq, letters[i]);
            } else {
                consonantMaxFreq = max(consonantMaxFreq, letters[i]);
            }
        }
        int maxfreq = vowelMaxFreq + consonantMaxFreq;
        return maxfreq;
    }
};