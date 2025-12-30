class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int fee;

    int rec(int index, bool bought, vector<int>& prices) {
        if(index >= n) return 0;

        if(dp[index][bought] != -1) return dp[index][bought];

        int profit = INT_MIN;

        if(!bought) { //not bought, then buy or skip
            profit = max(rec(index + 1, 0, prices), -prices[index] + rec(index + 1, true, prices));
        } else { // hold or sell
            profit = max(rec(index + 1, bought, prices), -fee + prices[index] + rec(index + 1, false, prices));
        }

        return dp[index][bought] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        this->fee = fee;
        dp = vector(n, vector<int>(2, -1));
        return rec(0, false, prices);
    }
};