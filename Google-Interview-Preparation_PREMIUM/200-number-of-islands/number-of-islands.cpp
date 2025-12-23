class Solution {
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid, int n, int m) {
        queue<pair<int,int>> q;
        visited[i][j] = 1;

        q.push({i, j});

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int ni = x + dx[k];
                int nj = y + dy[k];

                if(!isValid(ni, nj, n, m) || grid[ni][nj] != '1' || visited[ni][nj]) continue;
                q.push({ni, nj});
                visited[ni][nj] = 1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == 0 && grid[i][j] == '1') {
                    bfs(i, j, visited, grid, n, m);
                    ans++;
                }
            }
        }

        return ans;
    }
};