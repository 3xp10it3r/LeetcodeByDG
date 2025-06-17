class Solution {
public:
    int dp[100100][2][3];

    int rec(int level, int txn, int isBuy, vector<int>& prices, int n) {
        if(level == n || txn == 0) {
            return 0;
        }
        
        if(dp[level][isBuy][txn] != -1) return dp[level][isBuy][txn];

        int profit = 0;

        if(isBuy) {
            profit = max(-prices[level] + rec(level + 1, txn, 0, prices, n), rec(level + 1, txn, 1, prices, n));
        } else {
            profit = max(prices[level] + rec(level + 1, txn - 1, 1, prices, n), rec(level + 1, txn, 0, prices, n));
        }

        return dp[level][isBuy][txn] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        int n = prices.size();
        if(!n) return 0;

        return rec(0, 2, 1, prices, n);
    }
};