class Solution {
public:
    string reverse(string str) {
        int i = 0, j = str.length() - 1;
        while (i <= j) {
            swap(str[i], str[j]);
            i++;
            j--;
        }
        return str;
    }
    string reversePrefix(string word, char ch) {
        int first_occurrence = 0;
        string ans = "";
        string remaining_str = "";
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ch) {
                first_occurrence = i;
                break;
            }
        }
        for (int i = first_occurrence + 1; i < word.length(); i++) {
            remaining_str += word[i];
        }
        string str = "";
        for (int i = 0; i <= first_occurrence; i++) {
            str += word[i];
        }
        ans += reverse(str) + remaining_str;
        return ans;
    }
};