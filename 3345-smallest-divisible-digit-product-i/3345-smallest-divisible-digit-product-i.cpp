class Solution {
public:
    int digitProduct(int num) {
        int product = 1;
        while (num) {
            product *= num % 10;
            num /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while (digitProduct(n) % t != 0) {
            n++;
        }
        return n;
    }
};