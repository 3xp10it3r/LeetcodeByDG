class Solution {
public:
    int dp[101][101];
    int helper(int i, int j, int m, int n) {
        if(i == m-1 && j == n-1) {
            return 1;
        }

        if(i >= m || j >= n || i < 0 || j < 0) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = helper(i+1, j, m, n) + helper(i, j+1, m, n);

        return dp[i][j] = ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, m,n);
    }
};