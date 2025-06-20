class Solution {
public:
    int dp[201][201];
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    
    int dfs(int i, int j, vector<vector<int>>& matrix, int n, int m) {
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1;
        
        for(int k = 0; k < 4; k++) {
            int newI = i + dx[k];
            int newJ = j + dy[k];
            
            if(isValid(newI, newJ, n, m) && matrix[i][j] < matrix[newI][newJ]) {
                ans = max(ans, 1 + dfs(newI, newJ, matrix, n, m));
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, n, m));
            }
        }
        
        return ans;
    }
};