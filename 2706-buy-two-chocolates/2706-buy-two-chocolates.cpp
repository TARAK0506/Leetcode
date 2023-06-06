class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int amount=prices[0]+prices[1];
        if(amount<=money){
            return money-amount;
        }
        else{
            return money;
        }
    }
};