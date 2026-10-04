class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for (auto& ch : s) {
            if (ch == '(') {
                minOpen += 1;
                maxOpen += 1;
            } else if (ch == '*') {
                minOpen -= 1;
                maxOpen += 1;
            } else {
                minOpen -= 1;
                maxOpen -= 1;
            }
            if (maxOpen < 0) {
                return false;
            }
            minOpen = max(minOpen, 0);
        }
        return minOpen == 0;
    }
};