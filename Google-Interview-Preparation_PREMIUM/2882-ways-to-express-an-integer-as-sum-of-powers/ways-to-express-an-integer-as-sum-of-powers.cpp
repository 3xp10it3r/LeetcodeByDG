class Solution {
public:
    const int MOD = 1e9+7;

    int dp[301][301];

    int rec(int level, int n, int x, long long sum) {
        if(sum > n) return 0;

        if(level == n + 1) {
            if(sum == n) 
                return 1;
            return 0;
        }

        if(dp[level][sum] != -1) return dp[level][sum];

        int ans = 0;

        ans = rec(level + 1, n, x, sum) % MOD;
        ans = (ans + rec(level + 1, n, x, sum + pow(level, x)) % MOD) % MOD;

        return dp[level][sum] = ans % MOD;
    }

    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return rec(1, n, x, 0);
    }
};