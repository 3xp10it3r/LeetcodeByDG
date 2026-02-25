class Solution {
public:
    int n, m;
    int dp[101][101];
    int helper(vector<vector<int>>& obstacleGrid, int i, int j) {
        if(i == n-1 && j == m-1) {
            return 1;
        }

        if(i >= n || j >= m || i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(i + 1 < n && obstacleGrid[i+1][j] != 1) {
            ans += helper(obstacleGrid, i+1, j);
        }

        if(j + 1 < m && obstacleGrid[i][j+1] != 1) {
            ans += helper(obstacleGrid, i, j+1);
        }

        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp));

        if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1 ) return 0;

        return helper(obstacleGrid, 0, 0);
    }
};