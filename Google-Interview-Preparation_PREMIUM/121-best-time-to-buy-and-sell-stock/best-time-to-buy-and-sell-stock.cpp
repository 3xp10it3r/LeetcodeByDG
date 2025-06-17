class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0]; 
        int mxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            mxProfit = max(mxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return mxProfit;
    }
};