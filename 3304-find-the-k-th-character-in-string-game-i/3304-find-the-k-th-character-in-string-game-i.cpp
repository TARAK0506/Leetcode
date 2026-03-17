class Solution {
public:
    string generateString(string s, int k) {
        if (s.size() >= k)
            return s;
        string next = "";
        for (char ch : s) {
            next += (ch - 'a' + 1) % 26 + 'a';
        }
        return generateString(s + next, k);
    }
    char kthCharacter(int k) {
        string s = "a";
        s = generateString(s, k);
        return s[k - 1];
    }
};