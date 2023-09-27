class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        int hold = -prices[0];
        int sold = 0;
        for(int i = 0; i < len; i++)
        {
            hold = max(hold, sold-prices[i]);
            sold = max(sold, hold+prices[i]-fee);
        }
        return sold;
    }
};
