class Solution {
public:
    int fact(int num){
        if(num <= 1) return 1;
        return num * fact(num - 1);
    }
    bool isDigitorialPermutation(int n) {
        vector<int> factorial(10, 0);
        for(int digit = 0; digit <= 9; digit++){
            factorial[digit] = fact(digit);
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        int sum = 0, num = n;
        while(num){
            sum += factorial[num % 10];
            num /= 10;
        }
        string sums = to_string(sum);
        sort(sums.begin(), sums.end());
        return sums == s;
    }
};