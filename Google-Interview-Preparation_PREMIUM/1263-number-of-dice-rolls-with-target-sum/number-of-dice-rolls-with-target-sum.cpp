class Solution {
public:
    int dp[31][1001];
    const int MOD = 1e9 + 7;
    int helper(int level, int target, int n, int k) {

        if(level > n) return 0;

        if(level == n) {
            if(target == 0) return 1;
            return 0;
        }

        if(dp[level][target] != -1) return dp[level][target] % MOD;

        int ans = 0;

        for(int i = 1; i <= k; i++) {
            if(target - i >= 0)
            ans = (ans + helper(level + 1, target - i, n, k)) % MOD;
        }

        return dp[level][target] = ans % MOD;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(0, target, n, k);
    }
};