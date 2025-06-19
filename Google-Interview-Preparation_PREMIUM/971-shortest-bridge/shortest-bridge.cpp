class Solution {
public:
    vector<int> dx, dy;
    vector<vector<int>> vis;

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    void dfs(int i, int j, int n, int m, queue<pair<int,int>>& q, vector<vector<int>>& grid) {
        vis[i][j] = true;
        q.push({i, j});

        for(int k = 0; k < 4; k++) {
            int newI = i + dx[k];
            int newJ = j + dy[k];

            if(isValid(newI, newJ, n, m) && !vis[newI][newJ] && grid[newI][newJ] == 1) {
                dfs(newI, newJ, n, m, q, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vis.resize(n, vector<int>(m, 0));

        dx = {-1, 1, 0, 0};
        dy = {0, 0, -1, 1};

        int steps = 0;

        queue<pair<int,int>> q;

        int flag = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, n, m, q, grid);
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        

        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();

            for(int _i = 0; _i < sz; _i++) {
                auto node = q.front(); q.pop();

                int x = node.first;
                int y = node.second;

                for(int k = 0; k < 4; k++) {
                    int newI = x + dx[k];
                    int newJ = y + dy[k];

                    if(isValid(newI, newJ, n, m) && !vis[newI][newJ]) {
                        if(grid[newI][newJ] == 1) return steps;

                        q.push({newI, newJ});
                        vis[newI][newJ] = 1;
                    }
                }
            }
            
            steps++;
        }

        return 0;
    }
};