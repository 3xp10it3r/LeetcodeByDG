class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    void dfs(int i, int j, int n, int m, vector<vector<char>>& board, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && board[ni][nj] == 'X') {
                dfs(ni, nj, n, m, board, vis);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'X') {
                    dfs(i, j, n, m, board, vis);
                    ans++;
                }
            }
        }

        return ans;
    }
};