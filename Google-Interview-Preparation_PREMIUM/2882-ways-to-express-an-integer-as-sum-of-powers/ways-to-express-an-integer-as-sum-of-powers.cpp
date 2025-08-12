class Solution {
public:
    const int MOD = 1e9+7;

    int rec(int level, int n, int x, long long sum, vector<vector<int>>& dp) {
        if(sum > n) return 0;

        if(level == n + 1) {
            if(sum == n) 
                return 1;
            return 0;
        }

        if(dp[level][sum] != -1) return dp[level][sum];

        int ans = 0;

        ans = rec(level + 1, n, x, sum, dp) % MOD;
        ans = (ans + rec(level + 1, n, x, sum + pow(level, x), dp) % MOD) % MOD;

        return dp[level][sum] = ans % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int>(n + 1, -1));
        return rec(1, n, x, 0, dp);
    }
};