#define all(x) sort(begin(x), end(x), greater<int>())
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        all(prices), all(discounts);
        int i = 0, j = 0, m = prices.size(), n = discounts.size();
        double sum = 0;
        while (i < m && j < n) {
            int price = prices[i], discount = discounts[j];
            sum += (double)(price * (100 - discount)) / 100;
            i++;
            j++;
        }
        while (i < m) {
            sum += prices[i];
            i++;
        }
        return sum;
    }
};