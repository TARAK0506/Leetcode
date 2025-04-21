class Solution {
public:
    int generatefibonnaci(int k) {
        int a = 1, b = 1;
        while (b <= k) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        int cnt = 0;
        while (k > 0) {
            if (a <= k) {
                k -= a;
                cnt++;
            }
            int temp = b - a;
            b = a;
            a = temp;
        }
        return cnt;
    }
    int findMinFibonacciNumbers(int k) { 
        return generatefibonnaci(k); 
    }
};