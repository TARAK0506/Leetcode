class Solution {
public:
    int sumofDigits(int num) {
        int sum = 0;
        while (num) {
            int rem = num % 10;
            sum += rem;
            num /= 10;
        }
        return sum;
    }
    int productofDigits(int num) {
        int product = 1;
        while (num) {
            int rem = num % 10;
            product *= rem;
            num /= 10;
        }
        return product;
    }
    bool checkDivisibility(int n) {
        int sum = sumofDigits(n);
        int product = productofDigits(n);
        int totalSum = sum + product;
        return (n % totalSum == 0);
    }
};