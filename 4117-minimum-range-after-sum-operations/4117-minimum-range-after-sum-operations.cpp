class Solution {
public:
    int minRange(int a, int b, int c) {
        int minimum = min({a, b, c}), maximum = max({a, b, c});
        bool replaceA = (a > b + c), replaceB = (b > a + c),
             replaceC = (c > b + a);
        if (replaceA == 0 && replaceB == 0 && replaceC == 0) {
            return maximum - minimum;
        }
        if (replaceA == 1) {
            return b + c - minimum;
        } else if (replaceB == 1) {
            return c + a - minimum;
        }
        return a + b - minimum;
    }
};