class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int sell1 = 0, sell2 = 0;

        for (int i = 0; i < prices.size(); i++) {
            buy1 = min(buy1, prices[i]);
            sell1 = max(sell1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - sell1);
            sell2 = max(sell2, prices[i] - buy2);
        }

        return sell2;
    }
};