class Solution {
public:
    int rec(int level, vector<int>& coins, int sum, int amount, vector<vector<int>>& dp) {
        if(sum > amount) return 0;
        if(sum == amount) return 1;

        if(level >= coins.size()) return 0;

        if(dp[level][sum] != -1) return dp[level][sum];

        return dp[level][sum] = rec(level, coins, sum + coins[level], amount, dp) + 
               rec(level + 1, coins, sum, amount, dp);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return rec(0, coins, 0, amount, dp);
    }
};