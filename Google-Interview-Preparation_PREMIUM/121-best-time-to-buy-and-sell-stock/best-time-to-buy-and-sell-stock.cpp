class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0]; 
        int mxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            mxProfit = max(mxProfit, prices[i] - minPrice);
        }

        return mxProfit;
    }
};