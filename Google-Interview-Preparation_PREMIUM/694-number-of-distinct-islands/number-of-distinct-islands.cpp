class Solution {
public:
    vector<vector<int>> vis;
    vector<int> dx, dy;
    set<vector<pair<int,int>>> st;

    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

    void bfs(int i, int j, vector<vector<int>>& grid, int n, int m) {

        queue<pair<int, int>> q;

        vector<pair<int,int>> ans;
        ans.push_back({0,0});

        q.push({i, j});

        // int sourceNumber = i + (i-1) * j;

        while(!q.empty()) {
            auto node = q.front(); q.pop();

            if(vis[node.first][node.second]) continue;
            vis[node.first][node.second] = 1;

            for(int k = 0; k < 4; k++) {
                int newI = node.first + dx[k];
                int newJ = node.second + dy[k];

                if(isValid(newI, newJ, n, m) && !vis[newI][newJ] && grid[newI][newJ] == 1) {
                    ans.push_back({newI - i, newJ - j});
                    q.push({newI, newJ});
                }
            }
        }

        // sort(ans.begin(), ans.end());
        st.insert(ans);
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis.assign(n, vector<int>(m, 0));

        dx = {-1, 1, 0, 0};
        dy = {0, 0, -1, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j, grid, n, m);
                }
            }
        }

        return (int)st.size() ;
    }
};