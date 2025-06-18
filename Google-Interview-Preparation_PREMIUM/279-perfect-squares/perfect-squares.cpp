class Solution {
public:
    int dp[10010];

    int helper(int n) {
        if( n <= 0) return 0;

        if(dp[n] != -1) return dp[n];

        int ans = n; // considering 1 squares only at each level.

        for(int i = 1; i * i <= n; i++) {
            ans = min(ans, 1 + helper(n - i * i));
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i <= n; i++) {
            dp[i] = i;

            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};