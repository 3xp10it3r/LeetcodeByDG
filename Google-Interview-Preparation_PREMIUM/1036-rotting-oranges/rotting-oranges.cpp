class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int cntFresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }

                if(grid[i][j] == 1) cntFresh++;
            }
        }

        int ans = 0;
        int newRotten = 0;

        while(!q.empty()) {
            int sz = q.size();
            int curRotten = newRotten;
            for(int k = 0; k < sz; k++) {
                pair<int,int> node = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int ni = dx[i] + node.first;
                    int nj = dy[i] + node.second;

                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && !visited[ni][nj] && grid[ni][nj] == 1) {
                        q.push({ni, nj});
                        visited[ni][nj] = 1;
                        newRotten++;
                    }
                }
            }
            if(newRotten - curRotten != 0)
                ans++;
        }

        if(newRotten != cntFresh) return -1;

        return ans;
    }
};