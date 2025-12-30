class Solution {
public:
    // vector<vector<vector<int>>> dp;
    int n;
    // int k;
    // int rec(int index, bool bought, int txn, vector<int>& prices) {
    //     if(index >= n || txn >= k) return 0;

    //     if(dp[index][bought][txn] != -1) return dp[index][bought][txn];

    //     int profit = INT_MIN;

    //     if(!bought) { //not bought, then buy or skip
    //         profit = max(rec(index + 1, 0, txn, prices), 
    //                      -prices[index] + rec(index + 1, true, txn, prices));
    //     } else { // hold or sell
    //         profit = max(rec(index + 1, bought, txn, prices), 
    //                     prices[index] + rec(index + 1, false, txn + 1, prices));
    //     }

    //     return dp[index][bought][txn] = profit;
    // }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));

        
        for(int i = n - 1; i >= 0; i--) {
            for(int b = 0; b <= 1; b++) {
                for(int t = 0; t < k; t++) {

                    if(b == 0) {
                        curr[0][t] = max(
                            -prices[i] + ahead[1][t],
                            ahead[b][t]
                        );
                    } else {
                        curr[1][t] = max(
                            prices[i] + ahead[0][t+1],
                            ahead[1][t]
                        );
                    }
                }
            }
            ahead = curr;
        }

        return curr[0][0];
    }
};