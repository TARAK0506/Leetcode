class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size() - 1;
        while (i < n) {
            if (bits[i] == 0)
                i += 1;
            else
                i += 2;
        }
        return i == n;
    }
};