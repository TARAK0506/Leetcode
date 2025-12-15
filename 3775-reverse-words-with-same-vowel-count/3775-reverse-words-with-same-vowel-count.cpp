class Solution {
public:
    string reverseWord(string str) {
        int n = str.length();
        int i = 0, j = n - 1;
        while (i < j) {
            swap(str[i], str[j]);
            i++;
            j--;
        }
        return str;
    }
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int countVowel(string str) {
        int cnt = 0;
        for (auto& ch : str) {
            if (isVowel(ch))
                cnt++;
        }
        return cnt;
    }
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.emplace_back(word);
        }
        int cnt = countVowel(words[0]);
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            if (i != 0 && countVowel(words[i]) == cnt) {
                ans += reverseWord(words[i]);
            } else {
                ans += words[i];
            }
            if (i != words.size() - 1) {
                ans += " ";
            }
        }
        return ans;
    }
};