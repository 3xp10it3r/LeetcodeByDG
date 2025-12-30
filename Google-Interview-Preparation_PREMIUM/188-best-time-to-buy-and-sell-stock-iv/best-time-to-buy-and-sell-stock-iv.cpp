class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n;
    int k;
    int rec(int index, bool bought, int txn, vector<int>& prices) {
        if(index >= n || txn >= k) return 0;

        if(dp[index][bought][txn] != -1) return dp[index][bought][txn];

        int profit = INT_MIN;

        if(!bought) { //not bought, then buy or skip
            profit = max(rec(index + 1, 0, txn, prices), 
                         -prices[index] + rec(index + 1, true, txn, prices));
        } else { // hold or sell
            profit = max(rec(index + 1, bought, txn, prices), 
                        prices[index] + rec(index + 1, false, txn + 1, prices));
        }

        return dp[index][bought][txn] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp = vector(n, vector<vector<int>>(2, vector<int>(k, -1)));
        this->k = k;
        return rec(0, false, 0, prices);
    }
};