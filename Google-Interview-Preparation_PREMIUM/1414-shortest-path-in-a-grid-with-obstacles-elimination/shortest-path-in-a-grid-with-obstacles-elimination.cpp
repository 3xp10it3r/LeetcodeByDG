class Solution {
public:
    const vector<int> dx = {0, 0, -1, 1};
    const vector<int> dy = {-1, 1, 0, 0};

    vector<vector<vector<int>>> dist;
    vector<vector<vector<bool>>> vis;

    bool isValid(int x, int y, vector<vector<int>>& grid) {
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
    }

    void bfs(vector<vector<int>>& grid, int k) {
        queue<vector<int>> q;

        // steps, k, st, en
        q.push({0, 0, 0, 0});

        dist[0][0][0] = 0;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            int steps = node[0];
            int obsUsed = node[1];
            int cellI = node[2];
            int cellJ = node[3];

            if(vis[cellI][cellJ][obsUsed]) continue;
            vis[cellI][cellJ][obsUsed] = 1;

            for(int i = 0; i < 4; i++) {
                int nI = cellI + dx[i];
                int nJ = cellJ + dy[i];

                if(!isValid(nI, nJ, grid)) continue;

                int nextObsUsed = obsUsed + grid[nI][nJ];

                if(nextObsUsed > k || vis[nI][nJ][nextObsUsed]) continue;

                if(dist[nI][nJ][nextObsUsed] > steps + 1) {
                    q.push({steps + 1, nextObsUsed, nI, nJ});
                    dist[nI][nJ][nextObsUsed] = steps + 1;
                }
            } 
        }
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        dist.assign(n, vector<vector<int>>(m , vector<int>(k + 1, 1e9)));
        vis.assign(n, vector<vector<bool>>(m , vector<bool>(k + 1, false)));

        bfs(grid, k);

        int ans = 1e9;
        for(int i = 0; i <= k; i++){
            ans = min(dist[n-1][m-1][i], ans);
        }
        
        return (ans == 1e9) ? -1 : ans;
    }
};