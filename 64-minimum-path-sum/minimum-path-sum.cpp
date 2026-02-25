class Solution {
public:
    int n, m;
    int dp[201][201];

    int helper(vector<vector<int>>& grid, int i, int j) {
        if(i == n-1 && j == m-1) {
            return grid[i][j];
        }

        if(i >= n || j >= m) return 1e8;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        if(i+1 < n) {
            ans = min(ans, helper(grid, i+1, j));
        }

        if(j+1 < m) {
            ans = min(ans, helper(grid, i, j+1));
        }

        return dp[i][j] = ans + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return helper(grid, 0, 0);
    }
};