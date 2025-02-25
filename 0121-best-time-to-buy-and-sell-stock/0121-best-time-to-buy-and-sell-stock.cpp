class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
            } else {
                max_profit = std::max(prices[i] - lowest, max_profit);
            }
        }

        return max_profit;
    }
};