class Solution {
public:
    bool isBalanced(string num) {
        long long even_sum = 0, odd_sum = 0;
        int n = num.size();
        long long start = 0, end = n;
        while (start < end) {
            if (start % 2 == 0) {
                even_sum += num[start] - '0';
            } else {
                odd_sum += num[start] - '0';
            }
            start++;
        }
        return even_sum == odd_sum;
    }
};