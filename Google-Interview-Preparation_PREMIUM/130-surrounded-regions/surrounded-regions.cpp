class Solution {
public:
    vector<vector<int>> vis;
    vector<int> dx, dy;

    bool isValid(int i, int j, int n, int m){
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    void dfs(int i, int j, vector<vector<char>>& board, int n, int m) {
        vis[i][j] = true;

        for(int k = 0; k < 4; k++) {
            int nI = i + dx[k];
            int nJ = j + dy[k];

            if(isValid(nI, nJ, n, m) && !vis[nI][nJ] && board[i][j] == 'O') {
                dfs(nI, nJ, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vis.assign(n, vector<int>(m, 0));

        dx = {-1, 1, 0, 0};
        dy = {0, 0, -1, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m - 1) {
                    if(board[i][j] == 'O' && !vis[i][j])
                        dfs(i, j, board, n, m);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};