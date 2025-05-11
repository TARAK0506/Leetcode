class Solution {
public:
    bool isvowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int vowel_max_freq = 0, consonant_max_freq = 0;
        for (auto ch : mp) {
            if (isvowel(ch.first)) {
                vowel_max_freq = max(vowel_max_freq, ch.second);
            } else {
                consonant_max_freq = max(consonant_max_freq, ch.second);
            }
        }
        return consonant_max_freq + vowel_max_freq;
    }
};