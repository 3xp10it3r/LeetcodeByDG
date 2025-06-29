class Solution {
public:
    int m, n;
    long long dp[51][51][51];
    const int MOD = 1e9 + 7;

    long long helper(int i, int j, int maxMove) {
        if(i >= m || j >= n || i < 0 || j < 0) return 1;

        if(maxMove == 0) return 0;   

        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];

        return dp[i][j][maxMove] = (
            helper(i + 1, j, maxMove - 1) % MOD +
            helper(i - 1, j, maxMove - 1) % MOD +
            helper(i, j + 1, maxMove - 1) % MOD +
            helper(i, j - 1, maxMove - 1) % MOD
        ) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;

        memset(dp, -1, sizeof(dp));

        return (int)helper(startRow, startColumn, maxMove);
    }
};