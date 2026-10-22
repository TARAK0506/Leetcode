class Solution {
public:
    bool isSorted(string s) {
        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] > s[i])
                return false;
        }
        return true;
    }
    int minOperations(string s) {
        if (isSorted(s))
            return 0;
        if (s.length() == 2)
            return -1;

        char max_char = *max_element(begin(s), end(s));
        char min_char = *min_element(begin(s), end(s));
        if (s[0] == min_char || s[s.length() - 1] == max_char)
            return 1;

        char max_mid_char = *max_element(begin(s) + 1, end(s) - 1);
        char min_mid_char = *min_element(begin(s) + 1, end(s) - 1);
        if (s[0] > max_mid_char && s[s.length() - 1] < min_mid_char)
            return 3;

        return 2;
    }
};

// eac
// eaa